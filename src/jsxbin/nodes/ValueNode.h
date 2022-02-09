#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class ValueNode : public AstNode {
    public:
        explicit ValueNode(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        string value;
    };
} }
