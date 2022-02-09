#include "FunctionCallExpr.h"

void FunctionCallExpr::parse() {
    function = decoders::d_node(reader);
    args = decoders::d_node(reader);
    constructorCall = decoders::d_bool(reader);
}

string FunctionCallExpr::jsx() {
    string result = constructorCall ? "new " : "";
    ArgumentList *argList = (ArgumentList *) args;

    // {new }{funcName}({args})
    result += function->jsx() + '(' + (argList == nullptr ? "" : argList->jsx()) + ")";
    return result;
}
