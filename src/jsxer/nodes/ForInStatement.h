#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class ForInStatement : public AstNode {
    public:
        DEFINE_NODE_TYPE(ForInStatement);

        explicit ForInStatement(Reader& reader) : AstNode(reader) {}

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
