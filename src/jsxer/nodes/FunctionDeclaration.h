#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxer;

namespace jsxer { namespace nodes {
    class FunctionDeclaration : public AstNode {
    public:
        explicit FunctionDeclaration(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::FunctionDeclaration;
        }

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo bodyInfo;
        decoders::FunctionSignature signature;
        int _type;
    };
} }
