#include "FunctionCallExpr.h"

void FunctionCallExpr::parse() {
    function = decoders::d_node(reader);
    args = decoders::d_node(reader);
    constructorCall = decoders::d_bool(reader);
}

string FunctionCallExpr::to_string() {
    string result = constructorCall ? "new " : "";
    auto* argList = (ArgumentList*) args;

    // {new }{funcName}({args})
    result += function->to_string() + '(' + (argList == nullptr ? "" : argList->to_string()) + ")";
    return result;
}
