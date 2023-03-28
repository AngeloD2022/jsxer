#pragma once

#include <memory>

#include "../reader.h"
#include "node-types.h"

#include <fmt/printf.h>

namespace jsxer::nodes {
    class AstNode {
    public:
        explicit AstNode(Reader &reader) : reader(reader) {};

        virtual NodeType type() = 0;

        virtual string to_string() = 0;

        virtual void parse() = 0;
    public:
        static void print_tree_node(const Reader& r, const string& node_name) {
            fmt::print("{:{}}", "", r.indent_level() * r.indent_size());
            fmt::print("{} ({})\n", node_name, r.indent_level());
        }

    protected:
        Reader &reader;
    };

    using AstOpNode = std::shared_ptr<AstNode>;
}
