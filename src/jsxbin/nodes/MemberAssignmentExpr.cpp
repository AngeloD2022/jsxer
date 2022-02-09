#include "MemberAssignmentExpr.h"

void MemberAssignmentExpr::parse() {
    variable = decoders::d_node(reader);
    expression = decoders::d_node(reader);
    literal = decoders::d_variant(reader);
    shorthand = decoders::d_bool(reader);
}

string MemberAssignmentExpr::to_string() {
    if (shorthand) {
        auto* expr = (BinaryExpr*) expression;
        string value_assigned = literal.empty() ? expr->get_op() : literal;
        return variable->to_string() + ' ' + expr->get_op_name() + "= " + value_assigned;
    } else {
        string value_assigned = literal.empty() ? expression->to_string() : literal;
        return variable->to_string() + " = " + value_assigned;
    }
}
