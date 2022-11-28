#pragma once

#include "AstNode.h"
#include "BinaryExpression.h"
#include "../decoders.h"

using namespace jsxer;

namespace jsxer { namespace nodes {
    class LocalAssignmentExpression : public AstNode {
    public:
        explicit LocalAssignmentExpression(Reader& reader) : AstNode(reader) {}

        NodeType type() override {
            return NodeType::LocalAssignmentExpression;
        }

        void parse() override;

        string to_string() override;

        void suppress_declarative_keyword(bool value);

    private:
        string var_name;
        string literal;
        shared_ptr<AstNode> expression = nullptr;
        bool declarative_suppress = false;
        bool shorthand = false;
        bool declaration = false;
    };
} }
