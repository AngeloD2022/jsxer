#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class SimpleForStatement : public AstNode {
    public:
        DEFINE_NODE_TYPE(SimpleForStatement);

        explicit SimpleForStatement(Reader& reader) : AstNode(reader) {}

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
