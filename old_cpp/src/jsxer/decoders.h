#pragma once

#include "jsxer.h"

#include "reader.h"
#include "nodes/AstNode.h"

#include <string>
#include <vector>
#include <algorithm>

typedef uint8_t byte;

namespace jsxer::decoders {
    using jsxer::nodes::AstOpNode;

    struct Reference {
        ByteString id;
        bool flag;
    };

    struct LineInfo {
        size_t line_number;
        AstOpNode child;
        vector<string> labels;

        string lbl_statement() {
            string result;

            for (auto& label : labels) {
                result += label + ": \n";
            }

            return result;
        }

        [[nodiscard]]
        string create_body() const {
            return child == nullptr ? "" : child->to_string();
        }
    };

    enum FunctionType {
        NORMAL = 0,
        SCRIPT_CLOSURE = 1
    };

    struct FunctionSignature {
        string name;
        size_t num_args;
        size_t num_vars;
        size_t num_consts;
        map<size_t, string> variables;
        int flags = 0x10000;
    };

    AstOpNode d_node(Reader& reader);
    LineInfo d_line_info(Reader& reader);
    int d_literal_num(Reader& reader);
    string d_variant(Reader& reader);
    string d_number(Reader& reader);
    string d_sid(Reader& reader);
    string d_operator(Reader& reader);
    size_t d_length(Reader& reader);
    Reference d_id_ref(Reader& reader);
    Reference d_literal_ref(Reader& reader);
    byte d_byte(Reader& reader);
    vector<AstOpNode> d_children(Reader& reader);
    FunctionSignature d_fn_sig(Reader& reader);

    // decoding utilities...
    bool valid_id(const string& value);
    bool valid_id(const ByteString& value);
    bool valid_xml_attribute(const ByteString &value);
    bool is_integer(const string& value);
    bool is_integer(const ByteString& value);

}
