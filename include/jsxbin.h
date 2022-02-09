#pragma once

#include <string>

using std::string;

enum class JsxbinVersion : unsigned short {
    Invalid = (unsigned short) -1,

    v10 = 0x0100,
    v20 = 0x0200,
    v21 = 0x0201,
};

namespace jsxbin {
    int decompile(const string& input, string& output);
}
