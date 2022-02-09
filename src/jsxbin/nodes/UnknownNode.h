#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class UnknownNode : public AstNode {
    public:
        explicit UnknownNode(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        string id;
        AstNode *node;
    };
} }
