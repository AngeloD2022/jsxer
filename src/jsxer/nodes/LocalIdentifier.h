#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class LocalIdentifier : public AstNode {
    public:
        explicit LocalIdentifier(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::LocalIdentifier;
        }

        void parse() override;

        string to_string() override;

    private:
        decoders::Reference reference;
        int _type = 0;
    };
}
