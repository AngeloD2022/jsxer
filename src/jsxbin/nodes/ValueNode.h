#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class ValueNode : public AstNode {
    public:
        explicit ValueNode(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        string value;
    };
}
