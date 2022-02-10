#pragma once

#include <string>

#include "common.h"

using std::string;

BEGIN_NS(jsxbin) BEGIN_NS(utils)

bool string_equal(const string &str1, const string &str2);

void string_replace_char(string& str, char search, char replace);

void string_strip_char(string& str, char search);

void replace_str_inplace(string& subject, const string& search, const string& replace);

string string_literal_escape(uint16_t value, bool capital = false);

END_NS(utils) END_NS(jsxbin)
