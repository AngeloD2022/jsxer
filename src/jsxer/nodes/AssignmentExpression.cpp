#include "AssignmentExpression.h"

void AssignmentExpression::parse() {
    variable = decoders::d_node(reader);
    expression = decoders::d_node(reader);
    literal = decoders::d_variant(reader);
    shorthand = reader.getBoolean();
}

string AssignmentExpression::to_string() {
    if (shorthand) {
        auto* expr = (BinaryExpression*) expression;
        string value_assigned = literal.empty() ? expr->get_op() : literal;
        return variable->to_string() + ' ' + expr->get_op_name() + "= " + value_assigned;
    } else {
        string value_assigned = literal.empty() ? expression->to_string() : literal;
        return variable->to_string() + " = " + value_assigned;
    }
}
