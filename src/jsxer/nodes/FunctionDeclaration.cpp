#include "FunctionDeclaration.h"

void FunctionDeclaration::parse() {
    bodyInfo = decoders::d_line_info(reader);
    signature = decoders::d_fn_sig(reader);
    _type = decoders::d_length(reader);
}

string FunctionDeclaration::to_string() {
    string result = "function ";
    string body = bodyInfo.create_body();
    if (signature.header_5 == 1) {
        // if it is a "wrapper function"...
        return body;
    }

    result += signature.name + '(';
    int j = 0;
    for (auto & parameter : signature.parameters) {
        result += parameter.first + (j + 1 == signature.parameters.size() ? "" : ", ");
        j++;
    }
    result += ") {\n" + body + "\n}";

    if (!signature.name.length()) {
        result = '(' + result + ')';
    }


    return result;
}
