#pragma once

#include "AbstractNode.h"
#include "ArgumentList.h"
#include "../decoders.h"
#include <vector>

using namespace jsxbin;

namespace jsxbin::nodes {
    class ArrayExpr : public AbstractNode {
    public:
        explicit ArrayExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        ArgumentList* argumentList;

    };
}
