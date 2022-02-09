#include "ConditionalExpr.h"
#include <typeinfo>
// AKA ternary expression

bool parenthesis(AstNode *node){
    return strcmp(typeid(node).name(), "ConditionalExpr") == 0
    || strcmp(typeid(node).name(), "ArgumentList") == 0;
}

void ConditionalExpr::parse() {
    condition = decoders::d_node(reader);
    node_true = decoders::d_node(reader);
    node_false = decoders::d_node(reader);
}

string ConditionalExpr::jsx() {
    return condition->jsx() + " ? " +
    (parenthesis(node_true) ? '('+node_true->jsx()+')' : node_true->jsx())
    + " : "
    + (parenthesis(node_false) ? '('+node_false->jsx()+')' : node_false->jsx());
}


