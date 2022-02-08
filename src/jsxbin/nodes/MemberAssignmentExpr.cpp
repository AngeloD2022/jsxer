#include "MemberAssignmentExpr.h"

void MemberAssignmentExpr::parse() {
    variable = decoders::d_node(scanState);
    expression = decoders::d_node(scanState);
    literal = decoders::d_variant(scanState);
    shorthand = decoders::d_bool(scanState);
}

string MemberAssignmentExpr::jsx() {
    if (shorthand) {
        BinaryExpr *expr = (BinaryExpr *)expression;
        string value_assigned = literal.empty() ? expr->get_op() : literal;
        return variable->jsx() + ' ' + expr->get_op_name() + "= " + value_assigned;
    } else {
        string value_assigned = literal.empty() ? expression->jsx() : literal;
        return variable->jsx() + " = " + value_assigned;
    }
}
