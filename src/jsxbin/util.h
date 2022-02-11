#pragma once

#include <string>

#include "common.h"
#include "reader.h"

using std::string;

BEGIN_NS(jsxbin) BEGIN_NS(utils)

bool string_equal(const string &str1, const string &str2);

void string_replace_char(string& str, char search, char replace);

void string_strip_char(string& str, char search);

void replace_str_inplace(string& subject, const string& search, const string& replace);

string string_literal_escape(uint16_t value, bool capital = false);

string string_literal_escape(const ByteString& value, bool capital = false);

string to_string_literal(const ByteString& value, bool capital = false);

string to_string(const ByteString& value);

int byte_length(uint64_t value);

bool is_double_type(double value);

uint64_t to_integer(double value);

string number_to_string(double value);

bool bytes_eq(const uint8_t* b1, const uint8_t* b2, size_t size);

void zero_mem(const void* buff, size_t size);

END_NS(utils) END_NS(jsxbin)
