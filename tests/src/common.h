#pragma once

#include <string>

#include <jsxer.h>

namespace jsxer::test {
    int decompile(const std::string& compiled, std::string& decompiled, const std::string& source = "") {
        int err = jsxer::decompile_test(compiled, decompiled);

        if (!source.empty()) {
            printf("--------------------- Source ---------------------\n");
            printf("%s\n", source.c_str());
        }

        printf("------------------- Decompiled -------------------\n");
        printf("%s\n", decompiled.c_str());
        printf("--------------------------------------------------\n");

        return err;
    }
}
