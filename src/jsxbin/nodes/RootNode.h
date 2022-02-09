#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class RootNode : AstNode {
    public:
        explicit RootNode(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        AstNode *child = nullptr;
    };
}
