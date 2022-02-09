#include "util.h"

#include <cstring>
#include <algorithm>

#define MIN(x,y) ((x < y) ? x : y)

bool jsxbin::utils::string_equal(const string& str1, const string& str2) {
    return strncmp(str1.c_str(), str2.c_str(), MIN(str1.length(), str2.length())) == 0;
}

void jsxbin::utils::string_replace_char(string& str, char search, char replace) {
    std::replace(str.begin(), str.end(), search, replace);
}

void jsxbin::utils::string_strip_char(string& str, char search) {
    str.erase(remove(str.begin(), str.end(), search), str.end());
}

void jsxbin::utils::replace_str_inplace(string& subject, const string& search, const string& replace) {
    size_t pos = 0;

    while ((pos = subject.find(search, pos)) != string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
}
