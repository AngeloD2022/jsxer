#pragma once

#include <string>
#include <cstdint>

#ifndef CONFIG_VERSION
    #define CONFIG_VERSION "0.0.0"
#endif

using std::string;

enum class JsxbinVersion : uint16_t {
    Invalid = (uint16_t) -1,

    v10 = 0x0100,
    v20 = 0x0200,
    v21 = 0x0201,
};

namespace jsxer {
    int decompile(const string& input, string& output, bool unblind = false);

    int decompile_test(const string& input, string& output, bool unblind = false);
}
