#include "ConditionalExpr.h"

#include <typeinfo>

bool parenthesis(AstNode* node){
    return strcmp(typeid(node).name(), "ConditionalExpr") == 0
    || strcmp(typeid(node).name(), "ArgumentList") == 0;
}

void ConditionalExpr::parse() {
    condition = decoders::d_node(reader);
    node_true = decoders::d_node(reader);
    node_false = decoders::d_node(reader);
}

string ConditionalExpr::to_string() {
    return condition->to_string() + " ? " +
           (parenthesis(node_true) ? '(' + node_true->to_string() + ')' : node_true->to_string())
           + " : "
           + (parenthesis(node_false) ? '(' + node_false->to_string() + ')' : node_false->to_string());
}


