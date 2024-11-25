#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class ForInStatement : public AstNode {
    public:
        explicit ForInStatement(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::ForInStatement;
        }

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo bodyInfo;
        AstOpNode loopVariable;
        AstOpNode objExpression;
        unsigned long length{};
        string id;
        bool forEach = false;
    };
}
