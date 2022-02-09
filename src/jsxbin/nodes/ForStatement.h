#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class ForStatement : public AstNode {
    public:
        explicit ForStatement(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo bodyInfo;
        AstNode *loopVar = nullptr;
        string iteratorInitial;
        AstNode *upperBound = nullptr;
        string stepSize;
        int length;
        string comparisonOperator;
    };
} }
