#pragma once

#include "jsxbin.h"

#include <string>

#ifdef _WIN32
    #define JSXDAPI __declspec(dllexport)
#else
    #define JSXDAPI
#endif

#ifdef __cplusplus
extern "C" {
#endif

JSXDAPI int decompile(const char* input, size_t in_len, char* output, size_t* out_len);

#ifdef __cplusplus
};
#endif