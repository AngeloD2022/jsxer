#pragma once

#include <memory>

#include "../reader.h"
#include "node-types.h"

namespace jsxer::nodes {
    class AstNode {
    public:
        explicit AstNode(Reader &reader) : reader(reader) {};

        virtual NodeType type() = 0;

        virtual string to_string() = 0;

        virtual void parse() = 0;

    protected:
        Reader &reader;
    };

    using AstOpNode = std::shared_ptr<AstNode>;
}
