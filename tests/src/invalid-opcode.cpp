#include <jsxer.h>

#include <string>

int main() {
    const std::string compiled = "@JSXBIN@ES@2.0@!";
    std::string decompiled;

    const int err = jsxer::decompile_test(compiled, decompiled);
    return err != 0 && decompiled.empty() ? 0 : 1;
}
