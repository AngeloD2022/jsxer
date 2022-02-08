#pragma once

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class FunctionDeclaration : public AbstractNode {
    public:
        explicit FunctionDeclaration(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info bodyInfo;
        decoders::function_signature signature;
        int type;
    };
}
