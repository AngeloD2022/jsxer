#include "FunctionDeclaration.h"

#include <fmt/printf.h>

namespace jsxer::nodes {
    enum VariableTypeRange : int {
        kArguments = 0x20000000,
        kVars = 0x40000000,
        kConsts = 0x60000000,
    };

    void FunctionDeclaration::parse() {
        bodyInfo = decoders::d_line_info(reader);
        signature = decoders::d_fn_sig(reader);
        flags = decoders::d_literal_num(reader);
    }

    string FunctionDeclaration::to_string() {

        string body = bodyInfo.create_body();

        vector<string> args;
        vector<string> vars;
        vector<string> consts;

        for (int i = 0; i < signature.num_args; ++i) {
            uint32_t k = kArguments + i;
            auto v = signature.variables[k];
            args.push_back(v);
        }

        // not used for de-compilation
//        for (int i = 0; i < signature.num_vars; ++i) {
//            uint32_t k = kVars + i;
//            auto v = signature.variables[k];
//            vars.push_back(v);
//        }

        // not used for de-compilation
//        for (int i = 0; i < signature.num_consts; ++i) {
//            uint32_t k = kConsts + i;
//            auto v = signature.variables[k];
//            consts.push_back(v);
//        }

        // If a "script closure"
        if (signature.flags & 0x10000) {

            if (!signature.name.empty()) {
                string q = decoders::valid_id(signature.name) ? "" : "\"";

                body = "#script " + q + signature.name + q + '\n' + body;
            }

            return body;
        }

        string args_string = utils::string_join(args, ", ");
        string result = "function " + signature.name + '(' + args_string + ") {\n" + body + "\n}";

//        if (signature.name.empty()) {
//            result = '(' + result + ')';
//        }

        return result;
    }
}
