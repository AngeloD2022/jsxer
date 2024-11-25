#pragma once

#include <string>

#include "common.h"

using std::string;
using std::vector;

BEGIN_NS(jsxer) BEGIN_NS(utils)

bool string_equal(const string &str1, const string &str2);

void string_replace_char(string& str, char search, char replace);

void string_strip_char(string& str, char search);

void replace_str_inplace(string& subject, const string& search, const string& replace);

string string_join(vector<string> strings, const string& delimiter);

string string_literal_escape(uint16_t value, bool capital = false);

string string_literal_escape(const ByteString& value, bool capital = false);

string to_string_literal(const ByteString& value, bool capital = false);

string to_string_literal(const string& value, bool capital = false);

string from_string_literal(const string &value);

string to_string(const ByteString& value);

ByteString to_byte_string(const string& value);

int byte_length(uint64_t value);

bool is_number_integer(double value);

bool is_number_double(double value);

string number_to_string(double value);

bool bytes_eq(const uint8_t* b1, const uint8_t* b2, size_t size);

void zero_mem(const void* buff, size_t size);

template<typename T, typename F>
T number_raw_cast(F value) {
    return *((T*) &value);
}

// returns an int repr of the number
// floating points are not expected here (not 2.1436 but 2.0)
template<typename T, typename F>
T number_as_int(F value) {
    if (utils::is_number_double(value)) {
        return static_cast<T>(value);
    } else {
        return number_raw_cast<T>(value);
    }
}

END_NS(utils) END_NS(jsxbin)
