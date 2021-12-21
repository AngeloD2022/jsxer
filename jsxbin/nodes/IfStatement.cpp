//
// Created by Angelo DeLuca on 12/21/21.
//

#include "IfStatement.h"
#include <typeinfo>


void IfStatement::parse() {
    bodyInfo = decoders::d_linfo(scanState);
    test = decoders::d_node(scanState);
    otherwise = decoders::d_node(scanState);
}

string IfStatement::jsx() {
    string result = bodyInfo.lbl_statement() + "if ("+test->jsx()+") { \n"
            + bodyInfo.create_body() + '}';

    if (otherwise == nullptr) {
        return result;
    }

    AbstractNode *current = otherwise;
    while (istype(current, "IfStatement") && ((IfStatement *)current)->otherwise != nullptr) {
        IfStatement *elif = (IfStatement *)current;
        result += '\n' + elif->bodyInfo.lbl_statement() + "else if (" + elif->test->jsx() + ") {\n"
                + elif->bodyInfo.create_body() + '}';

        current = elif->otherwise;
    }

    // WARNME: something feels wrong here...
    result += "\nelse {\n"+ current->jsx() + "\n}";

    return result;
}
