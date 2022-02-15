#include "CallExpression.h"

void CallExpression::parse() {
    function = decoders::d_node(reader);
    args = decoders::d_node(reader);
    constructorCall = reader.getBoolean();
}

string CallExpression::to_string() {
    string result = constructorCall ? "new " : "";
    auto* argList = (ListExpression*) args;

    // {new }{funcName}({args})
    result += function->to_string() + '(' + (argList == nullptr ? "" : argList->to_string()) + ")";
    return result;
}
