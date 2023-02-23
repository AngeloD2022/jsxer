#include "FunctionDeclaration.h"

namespace jsxer::nodes {
    void FunctionDeclaration::parse() {
        bodyInfo = decoders::d_line_info(reader);
        signature = decoders::d_fn_sig(reader);
        _type = (unsigned int) decoders::d_length(reader);
    }

    string FunctionDeclaration::to_string() {
        string body = bodyInfo.create_body();

        if (signature.func_type == decoders::FunctionType::SCRIPT_CLOSURE) {
            // if it is a "script closure"...
            if (!signature.name.empty()) {
                if (decoders::valid_id(signature.name)) {
                    body = "#script " + signature.name + "\n\n" + body;
                } else {
                    body = "#script \"" + signature.name + "\"\n\n" + body;
                }
            }

            return body;
        }

        string result = "function " + signature.name + '(';

        int j = 0;
        for (auto &parameter: signature.parameters) {
            result += parameter.first + (j + 1 == signature.parameters.size() ? "" : ", ");
            j++;
        }
        result += ") {\n" + body + "\n}";

        if (!signature.name.length()) {
            result = '(' + result + ')';
        }


        return result;
    }
}
