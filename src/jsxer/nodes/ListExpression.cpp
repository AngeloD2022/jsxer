#include "ListExpression.h"

void ListExpression::parse() {
    arguments = decoders::d_children(reader);
    sequence_expr = reader.getBoolean();
}

void ListExpression::set_for_loop(bool x) {
    this->for_loop = x;
}

string ListExpression::to_string() {
    string result;

    string delimiter = ", ";

    // TODO: fix declarations
    for (int i = 0; i < arguments.size(); ++i) {
        result += arguments[i]->to_string() + (i + 1 == arguments.size() ? "" : delimiter);
    }

    if (sequence_expr && !for_loop) {
        result = '(' + result + ')';
    }

    return result;
}