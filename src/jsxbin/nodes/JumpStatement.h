#pragma once

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class JumpStatement : public AbstractNode {
    public:
        explicit JumpStatement(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info labelInfo;
        string jmpLocation;
        bool breakStatement;
    };
}
