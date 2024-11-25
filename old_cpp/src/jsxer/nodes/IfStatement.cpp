#include "IfStatement.h"

namespace jsxer::nodes {
    void IfStatement::parse() {
        bodyInfo = decoders::d_line_info(reader);
        test = decoders::d_node(reader);
        otherwise = decoders::d_node(reader);
    }

    string IfStatement::to_string() {
        string result = bodyInfo.lbl_statement() + "if (" + test->to_string() + ") { \n"
                        + bodyInfo.create_body() + "\n}";

        if (otherwise == nullptr) {
            return result;
        }

        auto current = otherwise;

        while ((current->type() == NodeType::IfStatement) && std::dynamic_pointer_cast<IfStatement>(current)->otherwise != nullptr) {
            auto elif = std::dynamic_pointer_cast<IfStatement>(current);
            result += '\n' + elif->bodyInfo.lbl_statement() + "else if (" + elif->test->to_string() + ") {\n"
                      + elif->bodyInfo.create_body() + "\n}";

            current = elif->otherwise;
        }

        // WARN_ME: something feels wrong here...
        result += "\nelse {\n" + current->to_string() + "\n}";

        return result;
    }
}
