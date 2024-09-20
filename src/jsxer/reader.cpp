#include <memory>
#include "reader.h"
#include "util.h"

#include <fmt/format.h>


using namespace jsxer;
#define perror(msg) printf("[!] " msg ", POS: %lu\n", this->_cursor)

Reader::Reader(const string& jsxbin, bool unblind) {
    string _input = jsxbin;

    utils::string_strip_char(_input, ' ');
    utils::string_strip_char(_input, '\t');
    utils::string_strip_char(_input, '\r');
    utils::string_strip_char(_input, '\n');
    utils::string_strip_char(_input, '\\');

    size_t input_len = _input.length();

    _data.resize(input_len);
    memcpy(_data.data(), _input.data(), input_len);

    _start = _cursor = 0;
    _end = input_len - 1;
    _depth = 0;

    _error = ParseError::None;
    _version = JsxbinVersion::Invalid;
    _unblind = unblind;
}

JsxbinVersion Reader::version() const {
    return _version;
}

ParseError Reader::error() const {
    return _error;
}

size_t Reader::depth() const {
    return _depth;
}

bool Reader::should_unblind() const {
    return _unblind;
}

void Reader::step(int offset) {
    _cursor += offset;
}

Token Reader::peek(int offset) {
    return _data[_cursor + offset];
}

size_t Reader::get_node_depth() {
    if (_depth == 0){
        update_node_depth();
    }

    return _depth;
}

int Reader::parse_node_depth() {
    Token current = peek();

    if (current == 'A') {
        step();
        return 1;

    } else if (current == '0') {
        step();
        int levels = get() - 0x3f;

        if (levels > 0x1b) {
            return levels + parse_node_depth();
        }
        return levels;

    }

    return 0;
}

void Reader::update_node_depth() {
    _depth = parse_node_depth();
}

bool Reader::decrement_node_depth() {
    if (get_node_depth() == 0)
        return false;

    _depth--;
    return true;
}

bool Reader::verifySignature() {
    if (_data.empty()) {
        _error = ParseError::NoData;
        return false;
    }

    if (_data.size() < JSXBIN_SIGNATURE_LEN) {
        _error = ParseError::InvalidVersion;
        return false;
    }

    if ( utils::bytes_eq((uint8_t*) _data.data(), (uint8_t*) JSXBIN_SIGNATURE_V10, JSXBIN_SIGNATURE_LEN) ) {
        _version = JsxbinVersion::v10;
    } else if ( utils::bytes_eq((uint8_t*) _data.data(), (uint8_t*) JSXBIN_SIGNATURE_V20, JSXBIN_SIGNATURE_LEN) ) {
        _version = JsxbinVersion::v20;
    } else if ( utils::bytes_eq((uint8_t*) _data.data(), (uint8_t*) JSXBIN_SIGNATURE_V21, JSXBIN_SIGNATURE_LEN) ) {
        _version = JsxbinVersion::v21;
    } else {
        _error = ParseError::InvalidVersion;
        return false;
    }

    _start = _cursor += JSXBIN_SIGNATURE_LEN;

    return true;
}

Token Reader::get() {
    Token token = _next();

    while (_ignorable(token)) {
        token = _next();
    }

    return token;
}

Byte Reader::getByte() {
    if (_depth > 0) {
        --_depth;
        return 0;
    }

    Token m = get();

    if (m == '0') {
        Token n = get();

        if (n > 0x5A) {
            goto error8;
        } else {
            _depth = n - 0x40;
            return 0;
        }
    } else if (m > 0x5A) {
        if (m > 0x6E) {
            goto error8;
        } else {
            Token z = get();
            uint8_t l, r = 32 * (m + 1);

            if (z > 0x5A) {
                if (z > 0x66) {
                    goto error8;
                } else {
                    l = z - 0x47;
                }
            } else {
                l = z - 0x41;
            }

            return (l | r);
        }
    }

    return m - 0x41;

error8:
    _error = ParseError::DecodeError;
    perror("Parse Error at getByte()");
    return 0;
}

Number Reader::getNumber() {
    if (_depth > 0) {
        --_depth;
        return 0.0;
    }

    Token t = get();
    Number res = 0, sign = (t != 'y') ? 1.0 : (t = get(), -1.0);

    switch (t) {
        case '2':
        case '4':
        case '8': {
            for (int i = 0; i < t - 48; ++i) {
                ((Byte*) &res)[i] = getByte();
            }
            break;
        }
        default: {
            step(-1);
            res = getByte();
            break;
        }
    }

    return sign * res;
}

ByteString Reader::getString() {
    ByteString result;

    auto length = utils::number_as_int<size_t>(getNumber());

    for (int i = 0; i < length; ++i) {
        // Each char is a unicode (utf-16) codepoint.
        auto u16_ch = utils::number_as_int<uint16_t>(getNumber());
        result.push_back(u16_ch);
    }

    return result;
}

bool Reader::getBoolean() {
    Token t = get();

    if (t == 't') {
        return true;
    } else if (t == 'f') {
        return false;
    } else {
        _error = ParseError::DecodeError;
        perror("Parse Error at getBoolean()");
    }

    return false;
}

ByteString Reader::readSID(bool operator_context) {
    ByteString symbol;
    Number id;

    if (get() == 'z') {
        symbol = getString();
        id = getNumber();

        int id_int = utils::number_as_int<int>(id);

        // if a symbol name is obfuscated, rename it to something more sensible...
        if (_unblind && jsxer::deob::jsxblind_should_substitute(deobfuscationContext, symbol, operator_context)) {
            string deobfuscated = "symbol_" + fmt::to_string(id_int);
            symbol = utils::to_byte_string(deobfuscated);
        }

        addSymbol(id, symbol);
    } else {
        step(-1);
        id = getNumber();
        symbol = getSymbol(id);
    }

    return symbol;
}

ByteString Reader::readLiteral() {
    ByteString symbol;
    Number id;

    if (get() == 'z') {
        symbol = getString();
        id = getNumber();
        addSymbol(id, symbol);
    } else {
        step(-1);
        id = getNumber();
        symbol = getSymbol(id);
    }

    return symbol;
}

OpVariant Reader::getVariant() {
    if (get() == 'n') {
        return nullptr;
    } else {
        step(-1);
    }

    uint8_t type = get() - 'a';

    OpVariant result = std::make_shared<Variant>();
    switch (type) {
        case 0: // 'a' - also recognized as a null at runtime.
            // looks like it's meant for undefined, but not utilized.
            result->doErase();

            // TODO: find a better way for this
            result->setNull();
            break;
        case 1: // 'b' - null always encoded to 'b'
            // null type
            result->setNull();
            break;
        case 2: // 'c'
            // Boolean type
            result->setBool(getBoolean());
            break;
        case 3: // 'd'
            // Number type
            result->setDouble(getNumber());
            break;
        case 4: // 'e'
            // String type
            result->setString(getString());
            break;

        default:
            _error = ParseError::DecodeError;
            perror("Parse Error at getVariant()");
            break;
    }

    return result;
}

Token Reader::_next() {
    if (_cursor < _end) {
        return _data[_cursor++];
    }

    _error = ParseError::ReachedEnd;

    return _data[_end];
}

bool Reader::_ignorable(Token value) {
    switch (static_cast<char>(value)) {
        case ' ':
        case '\t':
        case '\r':
        case '\n':
            return true;
        default:
            return false;
    }
}

ByteString Reader::getSymbol(Number id) {
    return _symbols[id];
}

void Reader::addSymbol(Number id, const ByteString& symbol) {
    _symbols[id] = symbol;
}

int Reader::getInt() {
    Number val = getNumber();
    return int(val);
}

short Reader::getShort() {
    Number val = getNumber();
    return short(val);
}

Variant::Variant() {
    _type = VariantType::None;
    doErase();
}

void Variant::setNull() {
    _type = VariantType::Null;
    doErase();
}

void Variant::setBool(bool value) {
    _type = VariantType::Boolean;
    doErase();
    _value._bool = value;
}

void Variant::setDouble(double value) {
    _type = VariantType::Number;
    doErase();
    _value._double = value;
}

void Variant::setString(const ByteString& value) {
    _type = VariantType::String;
    doErase();
    _value._string = value;
}

void Variant::doErase() {
    if (_type == VariantType::String) {
        _value._string.clear();
    }

    utils::zero_mem(&_value, sizeof(ValueType));
}

String Variant::toString() {
    switch (_type) {
        case VariantType::Undefined: return "undefined";
        case VariantType::Null: return "null";
        case VariantType::Boolean:
            return _value._bool ? "true" : "false";
        case VariantType::Number:
            return utils::number_to_string(_value._double);
        case VariantType::String:
            return utils::to_string_literal(_value._string);
        default:
            return "";
    }
}
