#include "IfStatement.h"
#include <typeinfo>


void IfStatement::parse() {
    bodyInfo = decoders::d_line_info(reader);
    test = decoders::d_node(reader);
    otherwise = decoders::d_node(reader);
}

string IfStatement::jsx() {
    string result = bodyInfo.lbl_statement() + "if ("+test->jsx()+") { \n"
            + bodyInfo.create_body() + "\n}";

    if (otherwise == nullptr) {
        return result;
    }

    AstNode *current = otherwise;
    while (istype(current, "IfStatement") && ((IfStatement *)current)->otherwise != nullptr) {
        IfStatement *elif = (IfStatement *)current;
        result += '\n' + elif->bodyInfo.lbl_statement() + "else if (" + elif->test->jsx() + ") {\n"
                + elif->bodyInfo.create_body() + "\n}";

        current = elif->otherwise;
    }

    // WARNME: something feels wrong here...
    result += "\nelse {\n"+ current->jsx() + "\n}";

    return result;
}
