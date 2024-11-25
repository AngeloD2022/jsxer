#include "XMLUnaryRefExpression.h"

namespace jsxer::nodes {
    void XMLUnaryRefExpression::parse() {
        id = decoders::d_sid(reader);
        node = decoders::d_node(reader);
    }

    string XMLUnaryRefExpression::to_string() {
        return "// XMLUnaryRefExpression has no known syntactic representation.\n"
               "// To help add this, please create an issue on the Jsxer GitHub repository with the binary version\n"
               "// of this script attached, so that it can be researched. Thank you! <3\n"
               "// Create an issue here: https://github.com/AngeloD2022/jsxer";
    }
}
