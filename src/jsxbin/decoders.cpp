#include "util.h"
#include "decoders.h"
#include "nodes/nodes.h"

#define is_capital_alpha(x) x - 0x41 <= 0x19

using namespace jsxbin::decoders;

// Markers / constants...
const char NO_VARIANT = 0x6E;
const char ID_REFERENCE = 0x7A;
const char NEGATIVE_NUMBER = 0x79;
const char NUMBER_8_BYTES = 0x38;
const char NUMBER_4_BYTES = 0x34;
const char NUMBER_2_BYTES = 0x32;
const char BOOL_TRUE = 0x74;
const char BOOL_FALSE = 0x66;

// begin utility functions...
string fromISO8859(const unsigned char &value) {
    string result;
    if (value < 0x80) {
        result.push_back((char) value);
    } else {
        result.push_back((char) (0xC0 | value >> 6));
        result.push_back((char) (0x80 | (value & 0x3f)));
    }
    return result;
}
// end utility functions.

enum LiteralType {
    NUMBER,
    UTF8_STRING
};

string d_number_primitive(ScanState &scanState, int length, bool negative) {
     vector<byte> buffer(length);

    for (int i = 0; i < length; ++i) {
        buffer[i] = d_byte(scanState);
    }

    short sign = negative ? -1 : 1;

    // using the length, return the appropriate interpretation of the value...
    switch (length) {
        case 8:
            // result is a double...
            return to_string(*((double *)buffer.data()) * sign);
        case 4:
            // result is an integer...
            return to_string(*((uint32_t *)buffer.data()) * sign);
        case 2:
            // result is a short...
            return to_string(*((uint16_t *)buffer.data()) * sign);
        default:
            return "";
    }
}

string d_literal_primitive(ScanState &scanState, LiteralType literalType) {
    if (scanState.decrement_node_depth()) {
        return "";
    }

    bool negative = false;
    if (scanState.peek(0) == NEGATIVE_NUMBER) {
        negative = true;
        scanState.step();
    }

    char marker = scanState.peek(0);

    if (marker == NUMBER_4_BYTES) {
        scanState.step();
        string number = d_number_primitive(scanState, 4, negative);
        return number;

    } else if (marker == NUMBER_2_BYTES) {
        scanState.step();
        string number = d_number_primitive(scanState, 2, negative);
        return number;

    } else {
        byte num = d_byte(scanState);

        if (negative) {
            return to_string(-1 * (int) num);
        } else {
            if (literalType == LiteralType::NUMBER) {
                return to_string((unsigned char) num);
            } else {
                return fromISO8859((unsigned char) num);
            }
        }
    }
}

int decoders::d_literal_num(ScanState &scanState) {
    string value = d_literal_primitive(scanState, LiteralType::NUMBER);
    return value.empty() ? 0 : stoi(value);
}


AbstractNode *decoders::d_node(ScanState &scanState) {
    char marker = scanState.pop();

    if (marker == NO_VARIANT) {
        return nullptr;
    }

    AbstractNode *node = nodes::get((NodeType) marker, scanState);

    if (node != nullptr) {
        node->parse();

        return node;
    }

    // TODO: handle this
    return nullptr;
}

string decoders::d_number(ScanState &scanState) {
    char marker = scanState.peek(0);
    string num;

    // if the marker suggests
    if (marker == NUMBER_8_BYTES) {
        scanState.step();
        num = d_number_primitive(scanState, 8, false);
    } else {
        num = d_literal_primitive(scanState, LiteralType::NUMBER);
    }

    return num.empty() ? "0" : num;
}

byte decoders::d_byte(ScanState &scanState) {
    static const string alphabet_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef";

    // if it is nested, decrement depth level and return 0
    // (sorta feels like it should never happen)
    if (scanState.decrement_node_depth()) {
        return static_cast<byte>(0);
    }

    char cur = scanState.pop();

    // if result is capital letter...
    if (is_capital_alpha(cur)) {
        return static_cast<byte>(cur - 'A');
    } else {
        // cur must be within [103, 111]
        int n = (cur - 0x67) * 32; // ranges from 0 to 256
        char second = scanState.pop();
        size_t up_index = alphabet_upper.find(second);

        // takes advantage of 8-bit overflow for encoding...
        return (byte) (n + up_index);
    }
}

string decoders::d_variant(ScanState &scanState) {
    using jsxbin::utils::string_replace;

    string result;

    if (scanState.peek(0) == NO_VARIANT) {
        scanState.step();
        return "";
    }

    // types are 'a' or 'b':null 'c':boolean 'd':number 'e':string
    uint8_t type = scanState.pop() - 'a';

    switch (type) {
        case 0: // 'a'
        case 1: // 'b'
            // null type
            result = "null";
            break;
        case 2: // 'c'
            // boolean type
            result = d_bool(scanState) ? "true" : "false";
            break;
        case 3: // 'd'
            // number type
            result = d_number(scanState);
            break;
        case 4: // 'e'
            // string type
            result = d_string(scanState);
            string_replace(result, "\\", "\\\\");
            string_replace(result, "\"", "\\\"");
            string_replace(result, "\n", "\\n");
            string_replace(result, "\t", "\\t");
            string_replace(result, "\t", "\\t");
            string_replace(result, "\r", "\\r");

            result = '\"' + result + "\"";
            break;

        default:
            // TODO: Handle this
            break;
    }

    return result;
}

bool decoders::d_bool(ScanState &scanState) {
    char marker = scanState.pop();

    if (marker == BOOL_TRUE)
        return true;
    else if (marker == BOOL_FALSE)
        return false;

    // TODO: Handle this
    return false;
}

string decoders::d_string(ScanState &scanState) {

    // Parse length of string...
    string parsed_len = d_literal_primitive(scanState, LiteralType::NUMBER);
    int length = parsed_len.empty() ? 0 : stoi(parsed_len);

    if (length == 0)
        return "";

    string buf;
    for (int i = 0; i < length; ++i) {
        buf += d_literal_primitive(scanState, LiteralType::UTF8_STRING);
    }

    return buf;
}

reference decoders::d_ref(ScanState &scanState) {
    string id = d_ident(scanState);
    bool flag = false;

    if (scanState.get_version() == jsxbin_version::VERSION_2) {
        flag = d_bool(scanState);
    }

    return reference{ id, flag };
}

int decoders::d_length(ScanState &scanState) {
    string value = d_literal_primitive(scanState, LiteralType::NUMBER);
    return value.empty() ? 0 : abs(stoi(value));
}

string decoders::d_ident(ScanState &scanState) {
    char marker = scanState.peek(0);

    if (marker != ID_REFERENCE) {
        string id = to_string(d_length(scanState));
        return scanState.get_symbol(id);
    } else {
        char type = scanState.pop();
        string name = d_string(scanState);
        string id = to_string(d_length(scanState));
        scanState.add_symbol(id, name);
        return name;
    }
}

vector<AbstractNode *> decoders::d_children(ScanState &scanState) {
    int length = d_length(scanState);
    if (length == 0) {
        return {};
    }

    vector<AbstractNode *> result;
    for (int i = 0; i < length; ++i) {
        AbstractNode *child = d_node(scanState);
        if (child != nullptr)
            result.push_back(child);
    }

    return result;
}

line_info decoders::d_linfo(ScanState &scanState) {
    line_info result;

    result.line_number = d_length(scanState);
    result.child = d_node(scanState);

    int length = d_length(scanState);

    for (int i = 0; i < length; ++i) {
        result.labels.push_back(d_ident(scanState));
    }

    return result;
}

function_signature decoders::d_fsig(ScanState &scanState) {
    function_signature result;

    int length = d_length(scanState);
    if (length > 0) {
        for (int i = 0; i < length; ++i) {
            string parameterName = d_ident(scanState);
            int paramLength = d_length(scanState);

            // separate local variables from parameter list...
            if (paramLength > 0x1ffffc70 && paramLength < 0x202fbf00)
                result.parameters.insert_or_assign(parameterName, paramLength);
            else
                result.local_vars.insert_or_assign(parameterName, paramLength);
        }
    }

    result.header_1 = d_length(scanState);
    result.type = d_length(scanState);
    result.header_3 = d_length(scanState);
    result.name = d_ident(scanState);
    result.header_5 = d_literal_num(scanState);
    return result;
}

// decoding utilities...
bool decoders::valid_id(const string& value) {
    static const regex identifier("^[a-zA-Z_$][0-9a-zA-Z_$]*$");
    return regex_match(value.c_str(), identifier);
}

bool decoders::is_integer(const string& value) {
    size_t len = value.length();

    for (int i = 0; i < len; ++i) {
        if (!isdigit(value[i])) {
            return false;
        }
    }

    return true;
}