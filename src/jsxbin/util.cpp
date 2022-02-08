#include "util.h"

#include <cstring>

#define MIN(x,y) ((x < y) ? x : y)

bool jsxbin::utils::string_equal(const string& str1, const string& str2) {
    return strncmp(str1.c_str(), str2.c_str(), MIN(str1.length(), str2.length())) == 0;
}

bool jsxbin::utils::string_replace(string &str, const string &from, const string &to) {
    size_t pos = str.find(from);

    while (pos != string::npos) {
        str.replace(pos, from.length(), to);
        pos = str.find(from);
    }

    return true;
}

/*
bool replace_str(string &str, const string &from, const string &to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return true;
}
 */
