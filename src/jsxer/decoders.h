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
        int line_number;
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
        int flags;
        string name;
        int num_arguments;
        int num_local_const;
        FunctionType func_type;
        map<string, int> parameters;
        map<string, int> local_vars;
    };

    AstOpNode d_node(Reader& reader);
    LineInfo d_line_info(Reader& reader);
    int d_literal_num(Reader& reader);
    string d_variant(Reader& reader);
    string d_number(Reader& reader);
    string d_sid(Reader& reader);
    string d_operator(Reader& reader);
    int d_length(Reader& reader);
    Reference d_id_ref(Reader& reader);
    Reference d_literal_ref(Reader& reader);
    byte d_byte(Reader& reader);
    vector<AstOpNode> d_children(Reader& reader);
    FunctionSignature d_fn_sig(Reader& reader);

    // decoding utilities...
    bool valid_id(const string& value);
    bool valid_id(const ByteString& value);
    bool is_integer(const string& value);
    bool is_integer(const ByteString& value);
}
