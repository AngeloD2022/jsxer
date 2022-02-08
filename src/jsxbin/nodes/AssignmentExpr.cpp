#include "AssignmentExpr.h"

void AssignmentExpr::parse() {
    var_name = decoders::d_ident(scanState);
    int type = decoders::d_length(scanState);
    expression = decoders::d_node(scanState);
    literal = decoders::d_variant(scanState);
    shorthand = decoders::d_bool(scanState);
    declaration = decoders::d_bool(scanState);
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