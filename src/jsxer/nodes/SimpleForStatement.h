#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
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
        AstOpNode loopVar;
        string iteratorInitial;
        AstOpNode upperBound;
        string stepSize;
        size_t length{};
        string comparisonOperator;
    };
}
