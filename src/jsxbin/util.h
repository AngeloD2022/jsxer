#pragma once

#include <string>

using std::string;

namespace jsxbin::utils {
    bool string_equal(const string &str1, const string &str2);

    void string_replace_char(string& str, char search, char replace);

    void string_strip_char(string& str, char search);

    void replace_str_inplace(string& subject, const string& search, const string& replace);
};
