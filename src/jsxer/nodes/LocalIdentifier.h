#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class LocalIdentifier : public AstNode {
    public:
        DEFINE_NODE_TYPE(LocalIdentifier);

        explicit LocalIdentifier(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::Reference reference;
        int _type = 0;
    };
}
