#pragma once

#include <string>

using std::string;

enum class JsxbinVersion : unsigned short {
    Invalid = (unsigned short) -1,

    v10 = 0x0100,
    v20 = 0x0200,
    v21 = 0x0201,
};

enum jsxbin_version {
    VERSION_1,
    VERSION_2
};

namespace jsxbin {
    struct decompiler_options {
        bool tabbed = false;
    };

    int decompile(const string& input, string& output);
}
