#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class ForStatement : public AstNode {
    public:
        explicit ForStatement(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info bodyInfo;
        AstNode *loopVar = nullptr;
        string iteratorInitial;
        AstNode *upperBound = nullptr;
        string stepSize;
        int length;
        string comparisonOperator;
    };
}
