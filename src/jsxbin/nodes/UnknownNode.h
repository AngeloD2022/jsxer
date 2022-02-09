#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class UnknownNode : public AstNode {
    public:
        explicit UnknownNode(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        string id;
        AstNode *node;
    };
}
