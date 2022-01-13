//
// Created by Angelo DeLuca on 12/1/21.
//

#ifndef JSXBIN_DECOMPILER_JSXBIN_H
#define JSXBIN_DECOMPILER_JSXBIN_H
#include <string>

enum jsxbin_version {
    VERSION_1,
    VERSION_2
};

namespace jsxbin {

    struct decompiler_options {
        bool tabbed = false;
    };

    void decompile(const std::string &input, std::string &output);
}

#endif //JSXBIN_DECOMPILER_JSXBIN_H
