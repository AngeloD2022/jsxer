#pragma once

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class RegExpLiteral : public AbstractNode {
    public:
        explicit RegExpLiteral(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        string regex;
        string flags;
    };
}
