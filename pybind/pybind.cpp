//
// Created by Angelo DeLuca on 12/31/21.
//

#include "pybind.h"

jsxd_result decompile_jsxbin(char *fileContents) {
    std::string input(fileContents);
    std::string output;

    jsxbin::decompile(input, output);

    // convert from const char* to char* for output...
    const char* buf_a = output.c_str();
    char *buf_b = new char[output.length()];
    strcpy(buf_b, buf_a);

    return {buf_b, output.length()};
}
