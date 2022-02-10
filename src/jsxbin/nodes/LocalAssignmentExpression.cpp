#include "LocalAssignmentExpression.h"

void LocalAssignmentExpression::parse() {
    var_name = decoders::d_sid(reader);
    int type = decoders::d_length(reader);
    expression = decoders::d_node(reader);
    literal = decoders::d_variant(reader);
    shorthand = decoders::d_bool(reader);
    declaration = decoders::d_bool(reader);
}

string LocalAssignmentExpression::to_string() {
    string result = declaration ? "var " : "";

    if (shorthand) {
        auto* b = (BinaryExpression*) expression;

        // FIXME: i have a bad feeling about this one...
        string value_assigned = literal.empty() ? b->get_op() : literal;

        result += var_name + ' ' + b->get_op_name() + "= " + value_assigned;
    } else {
        string value_assigned = literal.empty() ? expression->to_string() : literal;
        result += var_name + " = " + value_assigned;
    }

    return result;
}