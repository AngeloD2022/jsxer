#include "TryStatement.h"

namespace jsxer::nodes {
    void TryStatement::parse() {
        tryBlock = decoders::d_line_info(reader);
        length = decoders::d_length(reader);
        finallyBlock = decoders::d_node(reader);

        for (int i = 0; i < length; ++i) {
            layers.push_back({decoders::d_sid(reader),
                              decoders::d_node(reader),
                              decoders::d_node(reader)});
        }
    }

    string TryStatement::to_string() {
        string result = tryBlock.lbl_statement() + "try {\n";
        result += tryBlock.create_body() + '\n';

        for (const auto& layer : layers) {
            result += "} catch (" + layer.arg;

            if (layer.exceptionFilter != nullptr)
                result += " if " + layer.exceptionFilter->to_string();

            result += ") {" + (layer.catchBlock == nullptr ? "" : layer.catchBlock->to_string()) + '\n';
        }

        if (finallyBlock != nullptr) {
            result += "} finally {\n";
            result += finallyBlock->to_string();
            result += '\n';
        }
        result += '}';

        return result;
    }
}
