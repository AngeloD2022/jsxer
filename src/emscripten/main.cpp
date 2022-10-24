#include <emscripten.h>
#include "jsxer.h"

#include <cstring>


extern "C" int jsxer_decompile(const char* input, size_t in_len, char* output, size_t* out_len, bool jsxblind_deobfuscate = false){
    printf("%s\n", input);
    std::string compiled(input, in_len), decompiled;

    int err = jsxer::decompile(compiled, decompiled, jsxblind_deobfuscate);
    printf("%s\n", std::to_string(decompiled.length()).c_str());

    if (err != 0) {
        if (output) {
            *output = '\0';
        }
        if (out_len) {
            *out_len = 0;
        }
        return err;
    }

    if (out_len) {
        if (output) {
            if ((decompiled.length() + 1) > *out_len) {
                return 1;
            }

            memset(output, '\0', *out_len);
            memcpy(output, decompiled.c_str(), decompiled.length());
        }

        *out_len = decompiled.length();

    }

    return 0;
}