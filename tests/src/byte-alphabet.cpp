#include <jsxer.h>

#include <cassert>
#include <string>

int main() {
    std::string output;

    // '[' is not in Adobe's A..Z/a..f low-part alphabet. The old decoder
    // accepted it because it only enforced an upper bound.
    assert(jsxer::decompile_test("@JSXBIN@ES@2.0@My[", output) != 0);
    assert(output.empty());
    return 0;
}
