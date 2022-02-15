#include "ListExpression.h"

void ListExpression::parse() {
    arguments = decoders::d_children(reader);
    unkBool = reader.getBoolean();
}

string ListExpression::to_string() {
    string result;

    for (int i = 0; i < arguments.size(); ++i) {
        result += arguments[i]->to_string() + (i + 1 == arguments.size() ? "" : ", ");
    }

    return result;
}