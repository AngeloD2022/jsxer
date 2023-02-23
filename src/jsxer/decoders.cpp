///
/// High-Level Decoding Procedures
///

#include "util.h"
#include "decoders.h"
#include "nodes/nodes.h"

enum LiteralType {
    NUMBER,
};

string d_number_primitive(jsxer::Reader& reader, int length, bool negative) {
     vector<byte> buffer(length);

    for (int i = 0; i < length; ++i) {
        buffer[i] = jsxer::decoders::d_byte(reader);
    }

    short sign = negative ? -1 : 1;

    // using the length, return the appropriate interpretation of the value...
    switch (length) {
        case 8:
            // result is a double...
            return std::to_string(*((double *)buffer.data()) * sign);
        case 4:
            // result is an integer...
            return std::to_string(*((uint32_t *)buffer.data()) * sign);
        case 2:
            // result is a short...
            return std::to_string(*((uint16_t *)buffer.data()) * sign);
        default:
            return "";
    }
}

string d_literal_primitive(jsxer::Reader& reader, LiteralType literalType) {
    // TODO: fix decoding (not decoding js string entirely)
    if (reader.decrement_node_depth()) {
        return "";
    }

    bool negative = false;
    if (reader.peek() == 'y') {
        negative = true;
        reader.step();
    }

    Token marker = reader.peek();

    if (marker == '4') {
        reader.step();
        string number = d_number_primitive(reader, 4, negative);
        return number;
    } else if (marker == '2') {
        reader.step();
        string number = d_number_primitive(reader, 2, negative);
        return number;
    } else {
        byte num = jsxer::decoders::d_byte(reader);

        if (negative) {
            return std::to_string(-1 * (int) num);
        } else {
            if (literalType == LiteralType::NUMBER) {
                return std::to_string((unsigned char) num);
            } else {
                return jsxer::utils::string_literal_escape(num);
            }
        }
    }
}

int jsxer::decoders::d_literal_num(Reader& reader) {
    string value = d_literal_primitive(reader, LiteralType::NUMBER);
    return value.empty() ? 0 : stoi(value);
}

jsxer::nodes::AstOpNode jsxer::decoders::d_node(Reader& reader) {
    Token marker = reader.get();

    auto node = nodes::get((jsxer::nodes::NodeType) marker, reader);

    if (node != nullptr) {
        node->parse();

        return node;
    }

    // TODO: handle this
    return nullptr;
}

string jsxer::decoders::d_number(Reader& reader) {
    string num;

    // if the marker suggests
    if (reader.get() == '8') {
        num = d_number_primitive(reader, 8, false);
    } else {
        reader.step(-1);
        num = d_literal_primitive(reader, LiteralType::NUMBER);
    }

    return num.empty() ? "0" : num;
}

byte jsxer::decoders::d_byte(Reader& reader) {
    return reader.getByte();
}

string jsxer::decoders::d_variant(Reader& reader) {
    auto var = reader.getVariant();
    if (var != nullptr) {
        string result = var->toString();
        return result;
    }

    // TODO: check
    return "";
}

jsxer::decoders::Reference jsxer::decoders::d_id_ref(Reader& reader) {
    auto id = reader.readSID();
    bool flag = false;

    if (reader.version() >= JsxbinVersion::v20) {
        flag = reader.getBoolean();
    }

    return Reference{ id, flag };
}

jsxer::decoders::Reference jsxer::decoders::d_literal_ref(Reader& reader) {
    auto id = reader.readLiteral();
    bool flag = false;

    if (reader.version() >= JsxbinVersion::v20) {
        flag = reader.getBoolean();
    }

    return Reference{ id, flag };
}

size_t jsxer::decoders::d_length(Reader& reader) {
    string value = d_literal_primitive(reader, LiteralType::NUMBER);

    if (!value.empty()) {
        if (value[0] == '-') {
            value.erase(0,1);
        }
        return stoul(value);
    }

    return 0;
}

string jsxer::decoders::d_sid(Reader& reader) {
    return utils::to_string(reader.readSID());
}

string jsxer::decoders::d_operator(Reader& reader) {
    return utils::to_string(reader.readSID(true));
}

vector<jsxer::nodes::AstOpNode> jsxer::decoders::d_children(Reader& reader) {
    size_t length = d_length(reader);

    vector<AstOpNode> result;
    for (int i = 0; i < length; ++i) {
        auto child = d_node(reader);
        if (child != nullptr) {
            result.push_back(child);
        }
    }

    return result;
}

jsxer::decoders::LineInfo jsxer::decoders::d_line_info(Reader& reader) {
    LineInfo result;

    result.line_number = d_length(reader);
    result.child = d_node(reader);

    size_t length = d_length(reader);

    for (int i = 0; i < length; ++i) {
        result.labels.push_back(d_sid(reader));
    }

    return result;
}

jsxer::decoders::FunctionSignature jsxer::decoders::d_fn_sig(Reader& reader) {
    FunctionSignature result;

    // identifiers/variables in func scope
    size_t num_idents = d_length(reader);
    for (int i = 0; i < num_idents; ++i) {
        string id = d_sid(reader);
        size_t id_seq = d_length(reader);

        // separate local variables from Arguments
        if (id_seq > 0x1ffffc70 && id_seq < 0x202fbf00)
            // 0x20000000 ... | sort it to get the sequence
            result.parameters[id] = id_seq;
        else
            // 0x40000000 ...
            result.local_vars[id] = id_seq;
    }

    // num of normal func args
    result.num_arguments = d_length(reader);

    // 0 -> normal func or Script Closure with no func local vars
    // 2 -> normal func with func local vars
    // 3 -> Script Closure with func local vars
    result.flags = (unsigned int) d_length(reader);

    // num of func local const variables
    result.num_local_const = d_length(reader);

    // name of the function or closure
    // if type == 3,
    //      Script name => #script name
    result.name = d_sid(reader);

    // 0 - normal func
    // 1 - Script Closure
    result.func_type = (FunctionType) d_literal_num(reader);

    return result;
}

inline
bool is_capital_alpha(uint32_t value) {
    return in_range_i('A', 'Z', value);
}

inline
bool is_small_alpha(uint32_t value) {
    return in_range_i('a', 'z', value);
}

inline
bool is_numerical_digit(uint32_t value) {
    return in_range_i('0', '9', value);
}

/* Validator for an id's first character */
inline
bool valid_id_0(uint32_t value) {
    return is_small_alpha(value) ||
        is_capital_alpha(value) ||
        ('_' == value) || ('$' == value);
}

/* Validator for an id's after first characters */
inline
bool valid_id_x(uint32_t value) {
    return valid_id_0(value) || is_numerical_digit(value);
}

// decoding utilities...
bool jsxer::decoders::valid_id(const string& value) {
    // ^[a-zA-Z_$][0-9a-zA-Z_$]*$
    size_t len = value.length();

    if (len > 0) {
        if (valid_id_0(value[0])) {
            for (int i = 1; i < len; ++i) {
                if (!valid_id_x(value[i])) {
                    return false;
                }
            }
        } else {
            return false;
        }
    } else {
        return false;
    }

    return true;
}

bool jsxer::decoders::valid_id(const ByteString& value) {
    // ^[a-zA-Z_$][0-9a-zA-Z_$]*$
    size_t len = value.size();

    if (len > 0) {
        if (valid_id_0(value[0])) {
            for (int i = 1; i < len; ++i) {
                if (!valid_id_x(value[i])) {
                    return false;
                }
            }
        } else {
            return false;
        }
    } else {
        return false;
    }

    return true;
}

bool jsxer::decoders::is_integer(const string& value) {
    size_t len = value.length();

    for (int i = 0; i < len; ++i) {
        if (!is_numerical_digit(value[i])) {
            return false;
        }
    }

    return true;
}

bool jsxer::decoders::is_integer(const ByteString& value) {
    size_t len = value.size();

    for (int i = 0; i < len; ++i) {
        if (!is_numerical_digit(value[i])) {
            return false;
        }
    }

    return true;
}
