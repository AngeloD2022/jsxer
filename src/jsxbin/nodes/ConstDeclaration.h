#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class ConstDeclaration : public AstNode {
    public:
        explicit ConstDeclaration(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

    private:
        string name;
        int length;
        AstNode *expression;
        string literal;
        bool boolean_1;
        bool boolean_2;
    };
} }
