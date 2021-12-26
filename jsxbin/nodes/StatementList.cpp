//
// Created by Angelo DeLuca on 12/26/21.
//

#include "StatementList.h"

void StatementList::parse() {
    body = decoders::d_linfo(scanState);

    length = decoders::d_length(scanState);
    for (int i = 0; i < length; ++i) {
        statements.push_back(decoders::d_node(scanState));
    }

    vector<AbstractNode*> children = decoders::d_children(scanState);
    statements.insert(statements.end(), children.begin(), children.end());
}

string StatementList::jsx() {
    string result;

    // A seemingly useless sorting step (by line number of statements) happens here (where this comment is) in the original project,
    // but I removed it. We'll see what happens when I test it...

    for (AbstractNode* statement : statements){
        string expression = statement->jsx();
        if(istype(statement, "ExprNode"))
            expression += ';';

        // fixme: adds an extra line break, fix later
        result += expression + '\n';
    }

    return body.lbl_statement() + result;
}
