#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxer;

namespace jsxer { namespace nodes {
    class SimpleForStatement : public AstNode {
    public:
        explicit SimpleForStatement(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::SimpleForStatement;
        }

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo bodyInfo;
        AstNode* loopVar = nullptr;
        string iteratorInitial;
        AstNode* upperBound = nullptr;
        string stepSize;
        int length;
        string comparisonOperator;
    };
} }
