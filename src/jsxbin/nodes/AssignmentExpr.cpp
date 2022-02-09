#include "AssignmentExpr.h"

void AssignmentExpr::parse() {
    var_name = decoders::d_ident(reader);
    int type = decoders::d_length(reader);
    expression = decoders::d_node(reader);
    literal = decoders::d_variant(reader);
    shorthand = decoders::d_bool(reader);
    declaration = decoders::d_bool(reader);
}

string AssignmentExpr::jsx() {
    string result = declaration ? "var " : "";

    if (shorthand) {
        BinaryExpr *b = (BinaryExpr *) expression;

        // FIXME: i have a bad feeling about this one...
        string value_assigned = literal.empty() ? b->get_op() : literal;

        result += var_name + ' ' + b->get_op_name() + "= " + value_assigned;
    } else {
        string value_assigned = literal.empty() ? expression->jsx() : literal;
        result += var_name + " = " + value_assigned;
    }

    return result;
}