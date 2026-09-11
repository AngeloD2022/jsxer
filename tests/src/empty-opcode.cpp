#include <jsxer.h>

#include <cassert>
#include <string>

int main() {
    std::string output;
    assert(jsxer::decompile_test("@JSXBIN@ES@2.0@n", output) == 0);
    assert(output.empty());
    return 0;
}
