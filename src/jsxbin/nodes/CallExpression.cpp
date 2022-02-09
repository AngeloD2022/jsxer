#include "CallExpression.h"

void CallExpression::parse() {
    function = decoders::d_node(reader);
    args = decoders::d_node(reader);
    constructor = decoders::d_bool(reader);
}

string CallExpression::to_string() {
    string result = constructor ? "new " : "";
    auto* argList = (ListExpression*) args;

    // {new }{funcName}({args})
    result += function->to_string() + '(' + (argList == nullptr ? "" : argList->to_string()) + ")";
    return result;
}
