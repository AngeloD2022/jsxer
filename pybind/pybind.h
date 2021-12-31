//
// Created by Angelo DeLuca on 12/31/21.
//

#ifndef JSXBIN_DECOMPILER_PYBIND_H
#define JSXBIN_DECOMPILER_PYBIND_H

#include "../jsxbin/jsxbin.h"
#include <string>

extern "C" {

    struct jsxd_result {
        char* data;
        unsigned long length;
    };

    jsxd_result decompile_jsxbin(char* fileContents);
};

#endif //JSXBIN_DECOMPILER_PYBIND_H
