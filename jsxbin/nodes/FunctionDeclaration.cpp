//
// Created by Angelo DeLuca on 12/21/21.
//

#include "FunctionDeclaration.h"

void FunctionDeclaration::parse() {
    bodyInfo = decoders::d_linfo(scanState);
    signature = decoders::d_fsig(scanState);
    type = decoders::d_length(scanState);
}

string FunctionDeclaration::jsx() {
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
    result += ") {\n" +body + "\n}";


    return result;
}
