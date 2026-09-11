#include <jsxer.h>

#include <cassert>
#include <string>

int main() {
    std::string output;

    assert(jsxer::decompile_test("@JSXBIN@ES@2.0@My", output) != 0);
    assert(output.empty());

    assert(jsxer::decompile_test("", output) != 0);
    return 0;
}
