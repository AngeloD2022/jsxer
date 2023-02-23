#pragma once

#include "jsxer.h"

#include <string>

#ifdef _WIN32
    #define ESD_PUBLIC_API __declspec(dllexport)
#elif defined(__GNUC__)
    #if __GNUC__ >= 4
        #define ESD_PUBLIC_API __attribute__ ((visibility ("default")))
    #else
        #define ESD_PUBLIC_API __attribute__ ((dllexport))
    #endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

ESD_PUBLIC_API int decompile(const char* input, size_t in_len, char* output, size_t* out_len, bool unblind = false);

#ifdef __cplusplus
};
#endif
