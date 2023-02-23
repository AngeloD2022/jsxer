#include "CallExpression.h"

namespace jsxer::nodes {
    void CallExpression::parse() {
        function = decoders::d_node(reader);
        args = decoders::d_node(reader);
        constructorCall = reader.getBoolean();
    }

    string CallExpression::to_string() {
        string result = constructorCall ? "new " : "";
        auto argList = std::dynamic_pointer_cast<ListExpression>(args);

        // {new }{funcName}({args})
        result += function->to_string() + '(' + (argList == nullptr ? "" : argList->to_string()) + ")";
        return result;
    }
}
