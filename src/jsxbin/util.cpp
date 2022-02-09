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

string string_from_ISO8859(unsigned char value) {
    string result;

    if (value < 0x80) {
        result.push_back((char) value);
    } else {
        result.push_back((char) (0xC0 | value >> 6));
        result.push_back((char) (0x80 | (value & 0x3f)));
    }

    return result;
}

END_NS(utils) END_NS(jsxbin)
