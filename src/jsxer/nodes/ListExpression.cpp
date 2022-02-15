#include "ListExpression.h"

void ListExpression::parse() {
    arguments = decoders::d_children(reader);
    sequence_expr = reader.getBoolean();
}

string ListExpression::to_string() {
    string result;

    // TODO: fix declarations
    for (int i = 0; i < arguments.size(); ++i) {
        result += arguments[i]->to_string() + (i + 1 == arguments.size() ? "" : ", ");
    }

    if (sequence_expr) {
        result = '(' + result + ')';
    }

    return result;
}