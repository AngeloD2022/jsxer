#include "util.h"

#include <cstring>
#include <algorithm>

BEGIN_NS(jsxbin) BEGIN_NS(utils)

bool string_equal(const string& str1, const string& str2) {
    return strncmp(str1.c_str(), str2.c_str(), MIN(str1.length(), str2.length())) == 0;
}

void string_replace_char(string& str, char search, char replace) {
    std::replace(str.begin(), str.end(), search, replace);
}

void string_strip_char(string& str, char search) {
    str.erase(remove(str.begin(), str.end(), search), str.end());
}

void replace_str_inplace(string& subject, const string& search, const string& replace) {
    size_t pos = 0;

    while ((pos = subject.find(search, pos)) != string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
}

#define HEX_CHARSET_CAPITAL ("0123456789" "ABCDEF")
#define HEX_CHARSET_SMALL   ("0123456789" "abcdef")

string unicode_escape(uint16_t value, bool capital = false) {
    auto* cs = capital ? HEX_CHARSET_CAPITAL : HEX_CHARSET_SMALL;
    char result[] = { '\\', 'u', '0', '0', '0', '0', '\0' };

    for (int i = 0; i < 4; ++i) {
        auto hc = cs[(value >> (4 * i)) & 0xF];
        result[sizeof(result) - (i + 2)] = hc;
    }

    return result;
}

string hex_escape(uint8_t value, bool capital = false) {
    auto* cs = capital ? HEX_CHARSET_CAPITAL : HEX_CHARSET_SMALL;
    char result[] = { '\\', 'x', '0', '0', '\0' };

    for (int i = 0; i < 2; ++i) {
        auto hc = cs[(value >> (4 * i)) & 0xF];
        result[sizeof(result) - (i + 2)] = hc;
    }

    return result;
}

bool is_non_printable_ascii(uint8_t value) {
    // ([\x00-\x07\x0E-\x1F\x7F])
    return in_range_i(0, 7, value) ||
           in_range_i(0x0E, 0x1F, value) || (value == 0x7F);
}

bool is_non_printable_utf8(uint8_t value) {
    // ([\x00-\x07\x0E-\x1F\x7F\x80-\xFF])
    return is_non_printable_ascii(value) || in_range_i(0x80, 0xFF, value);
}

string escape_hex_or_unicode(uint16_t value, bool capital = false) {
    if (in_range_i(0x00, 0xFF, value)) {
        return hex_escape((uint8_t) value, capital);
    }

    return unicode_escape(value, capital);
}

string string_literal_escape(uint16_t value, bool capital) {
    switch (value)
    {
        case '\b': return "\\b";
        case '\f': return "\\f";
        case '\n': return "\\n";
        case '\r': return "\\r";
        case '\v': return "\\v";
        case '\t': return "\\t";
        case '\"': return "\\\"";
        case '\'': return "\\\'";
        case '\\': return "\\\\";
        default:
            return is_non_printable_utf8((uint8_t) value)
                ? escape_hex_or_unicode(value, capital)
                : string(1, (char) value);
    }
}

bool bytes_eq(const uint8_t* b1, const uint8_t* b2, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (b1[i] != b2[i]) {
            return false;
        }
    }

    return true;
}


END_NS(utils) END_NS(jsxbin)
