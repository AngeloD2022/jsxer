#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
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
        AstNode *loopVariable = nullptr;
        AstNode *objExpression = nullptr;
        int length;
        string id;
        bool forEach = false;
    };
} }
