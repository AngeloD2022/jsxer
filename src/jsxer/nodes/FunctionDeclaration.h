#pragma once

#include "AstNode.h"
#include "../decoders.h"

namespace jsxer::nodes {
    class FunctionDeclaration : public AstNode {
    public:
        DEFINE_NODE_TYPE(FunctionDeclaration);

        explicit FunctionDeclaration(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo bodyInfo;
        decoders::FunctionSignature signature;
        unsigned int _type{};
    };
}
