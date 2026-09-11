#include "Program.h"

namespace jsxer::nodes {
    void Program::parse() {
        body = decoders::d_node(reader);
    }

    string Program::to_string() {
        return body == nullptr ? "" : body->to_string();
    }
}
