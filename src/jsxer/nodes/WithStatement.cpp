#include "WithStatement.h"

namespace jsxer::nodes {
    void WithStatement::parse() {
        bodyInfo = decoders::d_line_info(reader);
        object = decoders::d_node(reader);
    }

    string WithStatement::to_string() {
        return bodyInfo.lbl_statement() + "with (" + object->to_string() + ") {\n" + bodyInfo.create_body() + "\n}";
    }
}
