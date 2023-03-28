#include "Program.h"

namespace jsxer::nodes {
    void Program::parse() {
        print_tree_node(reader, "Program");

        body = decoders::d_node(reader);
    }

    string Program::to_string() {
        return body->to_string();
    }
}