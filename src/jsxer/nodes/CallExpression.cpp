#include "CallExpression.h"
#include "Program.h"

#include <fmt/format.h>

namespace jsxer::nodes {
    void CallExpression::parse() {
        function = decoders::d_node(reader);
        args = decoders::d_node(reader);
        constructorCall = reader.getBoolean();
    }

    string CallExpression::to_string() {
        auto function_name = function->to_string();
        auto arguments = std::dynamic_pointer_cast<ListExpression>(args);
        bool needWrap = function->type() == NodeType::FunctionExpression;
        // {new }{funcName|funcBody}({args})

        if (function_name == "eval" && arguments->arguments.size() == 1 && !constructorCall) {
            // Check if it has a JSXBIN signature.

            string payload = utils::from_string_literal(arguments->arguments[0]->to_string());
            auto internal_reader = std::make_unique<Reader>(payload, reader.should_unblind());

            if (internal_reader->verifySignature()) {
                // If we've confirmed it to be a nested JSXBIN eval call, decompile and inline the results.

                auto internal_ast = std::make_unique<Program>(*internal_reader);
                internal_ast->parse();
                string result = internal_ast->to_string();

                if (result.back() == ';') {
                    result.pop_back();
                }

                return result;
            }

        }

        string result = (constructorCall ? "new " : "");
        result += (needWrap ? "(" : "")
                + function->to_string()
                + (needWrap ? ")" : "")
                + (arguments ? '(' + arguments->to_string() + ')' : "()");

        return result;
    }
}
