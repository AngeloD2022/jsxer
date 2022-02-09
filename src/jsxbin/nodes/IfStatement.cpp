#include "IfStatement.h"
#include <typeinfo>


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

    AstNode *current = otherwise;
    while ((current->type() == NodeType::IfStatement) && (((IfStatement *)current)->otherwise != nullptr)) {
        auto* elif = (IfStatement*) current;
        result += '\n' + elif->bodyInfo.lbl_statement() + "else if (" + elif->test->to_string() + ") {\n"
                  + elif->bodyInfo.create_body() + "\n}";

        current = elif->otherwise;
    }

    // WARNME: something feels wrong here...
    result += "\nelse {\n" + current->to_string() + "\n}";

    return result;
}
