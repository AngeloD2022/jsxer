#pragma once

#include "jsxbin.h"

#include "reader.h"
#include "nodes/AstNode.h"

#include <string>
#include <vector>
#include <algorithm>

typedef uint8_t byte;

using std::string;
using std::vector;
using std::map;

using namespace jsxbin::nodes;

BEGIN_NS(jsxbin) BEGIN_NS(decoders)
struct Reference {
    string id;
    bool flag;
};

struct LineInfo {
    int line_number;
    AstNode* child;
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

struct FunctionSignature {
    int type;
    string name;
    int header_1;
    int header_3;
    int header_5;
    map<string, int> parameters;
    map<string, int> local_vars;
};

AstNode* d_node(Reader& reader);
LineInfo d_line_info(Reader& reader);
int d_literal_num(Reader& reader);
string d_variant(Reader& reader);
string d_number(Reader& reader);
string d_sid(Reader& reader);
int d_length(Reader& reader);
Reference d_ref(Reader& reader);
byte d_byte(Reader& reader);
vector<AstNode*> d_children(Reader& reader);
FunctionSignature d_fn_sig(Reader& reader);

// decoding utilities...
bool valid_id(const string &value);
bool is_integer(const string &value);

END_NS(decoders) END_NS(jsxbin)
