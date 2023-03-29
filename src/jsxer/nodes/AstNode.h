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
        template<typename... Args>
        static string format_indented(int indent, fmt::format_string<Args...> format_str, Args&&... args) {
            string out = fmt::format("{:{}}", "", indent);
            out += fmt::format(format_str, std::forward<Args>(args)...);
            return out;
        }

        static void print_tree_node(const Reader& r, const string& node_name) {
            if (r.should_print_tree()) {
                fmt::print("{:{}}", "", r.tree_indent_level() * r.tree_indent_size());
                fmt::print("{} ({})\n", node_name, r.tree_indent_level());
            }
        }

    protected:
        Reader &reader;
    };

    using AstOpNode = std::shared_ptr<AstNode>;
}
