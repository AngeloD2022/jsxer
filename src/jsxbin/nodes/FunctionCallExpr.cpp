#include "FunctionCallExpr.h"

void FunctionCallExpr::parse() {
    function = decoders::d_node(scanState);
    args = decoders::d_node(scanState);
    constructorCall = decoders::d_bool(scanState);
}

string FunctionCallExpr::jsx() {
    string result = constructorCall ? "new " : "";
    ArgumentList *argList = (ArgumentList *) args;

    // {new }{funcName}({args})
    result += function->jsx() + '(' + (argList == nullptr ? "" : argList->jsx()) + ")";
    return result;
}
