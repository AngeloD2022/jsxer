#pragma once

#include <string>

using std::string;

namespace jsxbin::utils {
    bool string_equal(const string &str1, const string &str2);

    bool string_replace(string &str, const string &from, const string &to);
};
