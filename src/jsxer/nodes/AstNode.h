#pragma once

#include <memory>

#include "../reader.h"
#include "node-types.h"

#include <fmt/printf.h>

#define STRING(s) #s

#define DEFINE_NODE_TYPE(nt)        \
    NodeType type() override {      \
        return NodeType::nt;        \
    }                               \
                                    \
    string typeName() override {    \
        return STRING(nt);          \
    }

namespace jsxer::nodes {
    class AstNode {
    public:
        explicit AstNode(Reader &reader) : reader(reader) {};

        virtual NodeType type() = 0;

        virtual string typeName() = 0;

        virtual string to_string() = 0;

        virtual void parse() {
            print_tree_node(reader, typeName());
        };
    public:
        template<typename... Args>
        static string format_indented(int indent, fmt::format_string<Args...> format_str, Args&&... args) {
            string out = fmt::format("{:{}}", "", indent);
            out += fmt::format(format_str, std::forward<Args>(args)...);
            return out;
        }

        static void print_tree_node(const Reader& r, const string& node_name) {
            if (r.should_print_tree()) {
                fmt::print("{:{}}", "", r.parse_indent_level() * r.parse_indent_size());
                fmt::print("{} ({})\n", node_name, r.parse_indent_level());
            }
        }

    protected:
        Reader &reader;
    };

    using AstOpNode = std::shared_ptr<AstNode>;
}
