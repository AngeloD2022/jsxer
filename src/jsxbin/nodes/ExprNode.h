#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class ExprNode : public AstNode {
    public:
        explicit ExprNode(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo lineInfo;
        AstNode *expression = nullptr;
    };
} }
