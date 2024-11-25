#include "util.h"

#include <cstring>
#include <algorithm>
#include <cmath>

#include <fmt/format.h>

BEGIN_NS(jsxer) BEGIN_NS(utils)

bool string_equal(const string &str1, const string &str2) {
    return strncmp(str1.c_str(), str2.c_str(), MIN(str1.length(), str2.length())) == 0;
}

void string_replace_char(string &str, char search, char replace) {
    std::replace(str.begin(), str.end(), search, replace);
}

void string_strip_char(string &str, char search) {
    str.erase(remove(str.begin(), str.end(), search), str.end());
}

void replace_str_inplace(string &subject, const string &search, const string &replace) {
    size_t pos = 0;

    while ((pos = subject.find(search, pos)) != string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
}

#define HEX_CHARSET_CAPITAL ("0123456789" "ABCDEF")
#define HEX_CHARSET_SMALL   ("0123456789" "abcdef")

string unicode_escape(uint16_t value, bool capital = false) {
    auto *cs = capital ? HEX_CHARSET_CAPITAL : HEX_CHARSET_SMALL;
    char result[] = {'\\', 'u', '0', '0', '0', '0', '\0'};

    for (int i = 0; i < 4; ++i) {
        auto hc = cs[(value >> (4 * i)) & 0xF];
        result[sizeof(result) - (i + 2)] = hc;
    }

    return result;
}

string hex_escape(uint8_t value, bool capital = false) {
    auto *cs = capital ? HEX_CHARSET_CAPITAL : HEX_CHARSET_SMALL;
    char result[] = {'\\', 'x', '0', '0', '\0'};

    for (int i = 0; i < 2; ++i) {
        auto hc = cs[(value >> (4 * i)) & 0xF];
        result[sizeof(result) - (i + 2)] = hc;
    }

    return result;
}

bool is_non_printable_ascii(uint32_t value) {
    // ([\x00-\x07\x0E-\x1F\x7F])
    return in_range_i(0, 7, value) ||
           in_range_i(0x0E, 0x1F, value) || (value == 0x7F);
}

bool is_non_printable_utf8(uint32_t value) {
    // ([\x00-\x07\x0E-\x1F\x7F\x80-\xFF])
    return is_non_printable_ascii(value) || in_range_i(0x80, 0xFF, value);
}

bool is_non_printable_utf16(uint32_t value) {
    return is_non_printable_ascii(value) || in_range_i(0x80, 0xFF, value) || (value > 0xFF);
}

string escape_hex_or_unicode(uint16_t value, bool capital = false) {
    if (in_range_i(0x00, 0xFF, value)) {
        return hex_escape((uint8_t) value, capital);
    }

    return unicode_escape(value, capital);
}

string string_join(vector<string> strings, const string& delimiter) {
    string result;

    for (int i = 0; i < strings.size(); ++i) {
        result += strings[i];

        if (i + 1 != strings.size()) {
            result += delimiter;
        }
    }

    return result;
}

string string_literal_escape(uint16_t value, bool capital) {
    switch (value) {
        case '\b':
            return "\\b";
        case '\f':
            return "\\f";
        case '\n':
            return "\\n";
        case '\r':
            return "\\r";
        case '\v':
            return "\\v";
        case '\t':
            return "\\t";
        case '\"':
            return "\\\"";
        case '\'':
            return "\\\'";
        case '\\':
            return "\\\\";
        default:
            return is_non_printable_utf16(value)
                   ? escape_hex_or_unicode(value, capital)
                   : string(1, (char) value);
    }
}

string string_literal_escape(const ByteString &value, bool capital) {
    string res;

    for (const auto &c: value) {
        res += string_literal_escape(c, capital);
    }

    return res;
}

string string_literal_unescape(const string& value) {

    string result;

    for (int i = 0; i < value.size(); ++i) {
        if (value[i] != '\\' || i + 1 == value.size()) {
            result += value[i];
            continue;
        }

        i++;
        switch(value[i]) {
            case 'b':
                result += "\b";
                break;
            case 'f':
                result += "\f";
                break;
            case 'n':
                result += "\n";
                break;
            case 'r':
                result += "\r";
                break;
            case 'v':
                result += "\v";
                break;
            case 't':
                result += "\t";
                break;
            case '"':
                result += "\"";
                break;
            case '\'':
                result += "\'";
                break;
            default:
                result += '\\';
                result += value[i];
                break;
        }
    }

    return result;
}

string from_string_literal(const string &value) {

    string x = value;
    x.erase(0, 1);
    x.erase(x.size() - 1, 1);
    x = string_literal_unescape(x);

    return x;
}

string to_string_literal(const ByteString &value, bool capital) {
    string res = "\"";

    for (auto &c: value) {
        res += string_literal_escape(c, capital);
    }

    return res + "\"";
}

string to_string_literal(const string &value, bool capital) {
    string res = "\"";

    for (auto &c: value) {
        res += string_literal_escape(c, capital);
    }

    return res + "\"";
}

string to_string(const ByteString &value) {
    string res;

    for (auto &c: value) {
        res += (char) c;
    }

    return res;
}

ByteString to_byte_string(const string &value) {
    ByteString res;

    for (auto &c: value) {
        res.push_back((uint16_t) c);
    }

    return res;
}

vector<string> string_split(const string &str, const string &delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = str.find(delimiter, pos_start)) != string::npos) {
        token = str.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(str.substr(pos_start));
    return res;
}

int byte_length(uint64_t value) {
    int len = sizeof(uint64_t);
    auto *p = (uint8_t *) &value;

    while ((p[len - 1] == 0) && len) {
        len--;
    }

    return len;
}

string ltrim(const string &s, char target = ' ') {
    size_t start = s.find_first_not_of(target);
    return (start == string::npos) ? "" : s.substr(start);
}

string rtrim(const string &s, char target = ' ') {
    size_t end = s.find_last_not_of(target);
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}

string trim(const string &s, char target = ' ') {
    return rtrim(ltrim(s, target), target);
}

#define NUMBER_SIGN_BIT_MASK (1LL << 63) // 0x8000_0000_0000_0000

bool is_number_negative(double value) {
    // is the sign(63rd) bit is set
    return number_raw_cast<uint64_t>(value) & NUMBER_SIGN_BIT_MASK;
}

// Returns positive integer
uint64_t number_to_integer(double value) {
    // ignore the sign(63rd) bit
    return number_raw_cast<uint64_t>(value) & ~NUMBER_SIGN_BIT_MASK;
}

// Returns positive double
double number_to_double(double value) {
    // ignore the sign(63rd) bit
    return number_raw_cast<double>(number_to_integer(value));
}

bool is_number_integer(double value) {
    return byte_length(number_to_integer(value)) < 8;
}

bool is_number_double(double value) {
    return !is_number_integer(value);
}

string simplify_number_literal(const string &value) {
    string result = value;

    auto es = string_split(result, "e");
    if (es.size() > 1) {
        auto e2 = es[1];
        if (e2.length()) {
            char sign = e2[0];
            for (char i: e2.substr(1)) {
                if (i != '0') {
                    goto skip_e_sfy;
                }
            }
            result = es[0];
        }
    }

skip_e_sfy:
    auto ds = string_split(result, ".");

    // trim prefix zeroes
    auto d1 = ds[0];
    for (int i = 0; i < d1.length(); ++i) {
        if (d1[i] != '0') {
            d1 = d1.substr(i, d1.length() - i);
            break;
        }
    }
    result = d1;

    // trim suffix zeroes
    if (ds.size() > 1) {
        auto d2 = ds[1];

        if (d2.length()) {
            for (size_t i = d2.length() - 1; i >= 0; --i) {
                if (d2[i] != '0') {
                    d2 = d2.substr(0, i + 1);
                    break;
                }
            }
        }

        if (d2.length()) {
            result += '.' + d2;
        }
    }

    return result;
}

string number_to_string(double value) {
    // let's try fmt to do all the dirty works
    // TODO:
    //  Write a full NumberToString test to confirm
    //  if it's okay for us to keep fmt for this job
    {
        string result;

        // integer        -> 1-7 bytes
        // double         -> 8 bytes
        // sign           -> 63rd bit
        if (is_number_negative(value)) { // is the sign(63rd) bit is set
            result += '-';
        }

        if (is_number_integer(value)) { // is byte_length < 8
            auto i = number_to_integer(value);
            result += fmt::format("{}", i);
        } else {
            auto d = number_to_double(value);
            result += fmt::format("{}", d);
        }

        return result;
    }

    // our dirty impl
    {
        char _buff[40] = {0};
        int _fmt_len;
        string result;

        // integer        -> 1-7 bytes in memory
        // double         -> 8 bytes in memory
        // 63rd bit       -> sign
        if (is_number_negative(value)) {
            result += '-';
        }

        if (is_number_integer(value)) {
            // Integer
            _fmt_len = snprintf(
                    _buff, sizeof(_buff),
                    "%llu", number_to_integer(value)
            );
        } else {
            // Double
            int precision = 15;
            const char *fmt;

            switch (number_raw_cast<uint64_t>(value)) {
                case 0x7FEFFFFFFFFFFFFF:
                    return "1.7976931348623157e+308";
                case 0xFFEFFFFFFFFFFFFF:
                    return "-1.7976931348623157e+308";
                default: {
                    if ((value >= 1.0e21) || (floor(value) != value)) {
                        if ((value < 1.0e21) && (value >= 0.000001)) {
                            int l10 = (int) log10(value);
                            int fpn = (l10 >= 0) ? l10 : 0;

                            precision = 15 - (value >= 1.0) - fpn;
                            if (precision > 15) {
                                precision = 15;
                            }

                            fmt = "%20.*f";
                        } else {
                            fmt = "%20.*e";
                            precision -= 1;
                        }
                    } else if (value >= 1000000000.0) {
                        fmt = "%*.0f";
                    } else {
                        fmt = "%*.f";
                    }
                }
            }

            _fmt_len = snprintf(
                    _buff, sizeof(_buff),
                    fmt, precision, number_to_double(value)
            );
        }

        _buff[_fmt_len] = '\0';
        result += trim(_buff, ' ');

        return simplify_number_literal(result);
    }
}

bool bytes_eq(const uint8_t *b1, const uint8_t *b2, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (b1[i] != b2[i]) {
            return false;
        }
    }

    return true;
}

void zero_mem(const void *buff, size_t size) {
    for (int i = 0; i < size; ++i) {
        ((uint8_t *) buff)[i] = '\0';
    }
}

END_NS(utils) END_NS(jsxbin)
