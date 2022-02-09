#include "TryStatement.h"

void TryStatement::parse() {
    tryBlock = decoders::d_line_info(reader);
    length = decoders::d_length(reader);
    finallyBlock = decoders::d_node(reader);

    for (int i = 0; i < length; ++i) {
        layers.push_back({decoders::d_ident(reader),
                          decoders::d_node(reader),
                          decoders::d_node(reader)});
    }
}

string TryStatement::jsx() {
    string result = tryBlock.lbl_statement() + "try {\n";
    result += tryBlock.create_body() + '\n';

    for (int i = 0; i < layers.size(); ++i) {
        tc_layer layer = layers[i];

        result += "} catch (" + layer.arg;

        if (layer.exceptionFilter != nullptr)
            result += " if " + layer.exceptionFilter->jsx();

        result += ") {" + (layer.catchBlock == nullptr ? "" : layer.catchBlock->jsx()) + '\n';
    }

    if (finallyBlock != nullptr) {
        result += "} finally {\n";
        result += finallyBlock->jsx();
        result += '\n';
    }
    result += '}';

    return result;
}
