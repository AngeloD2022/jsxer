#include "reader.h"
#include "util.h"

using namespace jsxbin;

Reader::Reader(const string& jsxbin) {
    size_t input_len = jsxbin.length();

    _data.resize(input_len);
    memcpy(_data.data(), jsxbin.c_str(), input_len);

    _start = _cursor = 0;
    _end = input_len - 1;
    _depth = 0;

    _error = ParseError::None;
    _version = JsxbinVersion::Invalid;
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

        if ((n - 0x41) > 0x19) {
            goto error8;
        } else {
            _depth = n - 0x40;
            return 0;
        }
    } else if ((m - 0x41) > 0x19) {
        if ((m - 0x67) > 7) {
            goto error8;
        } else {
            Token z = get();
            uint8_t l, r = 32 * (m + 1);

            if ((z - 0x41) > 0x19) {
                if ((z - 0x61) > 5) {
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
    _error = ParseError::Error8;
    return 0;
}

Number Reader::getNumber() {
    if (_depth > 0) {
        --_depth;
        return 0.0;
    }

    Token t = get();
    Number res, sign = (t != 'y') ? 1.0 : (t = get(), -1.0);

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

    int length = (int) getNumber();

    for (int i = 0; i < length; ++i) {
        result.push_back((uint16_t) getNumber());
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
        _error = ParseError::Error8;
    }

    return false;
}

ByteString Reader::readSID() {
    Token t = get();

    ByteString symbol;
    Number id;

    if (t == 'z') {
        symbol = getString();
        id = getNumber();
        addSymbol((int) id, symbol);
    } else {
        id = getNumber();
        symbol = getSymbol((int) id);
    }

    return symbol;
}

// TODO return a Variant type
ByteString Reader::getVariant() {
    ByteString result;

    Token type = get() - 'a';

    switch (type) {
        case 0: // 'a' - also recognized as a null at runtime.
        case 1: // 'b' - null always encoded to 'b'
            // null type
            result = {'n', 'u', 'l', 'l'};
            break;
        case 2: // 'c'
            // Boolean type
            result = getBoolean()
                    ? ByteString({'t', 'r', 'u', 'e'})
                    : ByteString({'f', 'a', 'l', 's', 'e'});
            break;
        case 3: // 'd'
            // Number type
            for (auto& c: std::to_string(getNumber())) {
                result.push_back((uint16_t) c);
            };
            break;
        case 4: // 'e'
            // String type
            result.push_back('\"');
            for (auto& c: getString()) {
                result.push_back((uint16_t) c);
            };
            result.push_back('\"');
            break;

        default:
            // TODO: Handle this
            printf("Unexpected: %c\n", type);
            break;
    }

    return result;
}

string DataPool::get(const string &key) {
    return _pool.at(key);
}

void DataPool::add(const string &key, string value) {
    _pool[key] = std::move(value);
}

void DataPool::clear() {
    _pool.clear();
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

void Reader::addSymbol(int id, const ByteString& symbol) {
    _symbols[id] = symbol;
}

ByteString Reader::getSymbol(int id) {
    return _symbols[id];
}