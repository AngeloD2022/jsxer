#include "CallExpression.h"

#include <fmt/format.h>

namespace jsxer::nodes {
    void CallExpression::parse() {
        function = decoders::d_node(reader);
        args = decoders::d_node(reader);
        constructorCall = reader.getBoolean();
    }

    string CallExpression::to_string() {
        auto arguments = std::dynamic_pointer_cast<ListExpression>(args);
        bool needWrap = function->type() == NodeType::FunctionExpression;
        // {new }{funcName|funcBody}({args})

        string result = (constructorCall ? "new " : "");
        result += (needWrap ? "(" : "")
                + function->to_string()
                + (needWrap ? ")" : "")
                + (arguments ? '(' + arguments->to_string() + ')' : "()");

        return result;
    }
}
