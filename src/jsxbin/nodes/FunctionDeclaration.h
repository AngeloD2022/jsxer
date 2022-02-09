#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class FunctionDeclaration : public AstNode {
    public:
        explicit FunctionDeclaration(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        decoders::LineInfo bodyInfo;
        decoders::FunctionSignature signature;
        int type;
    };
} }
