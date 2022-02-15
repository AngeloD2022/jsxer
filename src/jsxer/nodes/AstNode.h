#pragma once

#include "../reader.h"
#include "node-types.h"

using std::string;

BEGIN_NS(jsxer) BEGIN_NS(nodes)

class AstNode {
public:
    explicit AstNode(Reader& reader) : reader(reader) {};
    virtual NodeType type() = 0;
    virtual string to_string() = 0;
    virtual void parse() = 0;
protected:
    Reader& reader;
};

END_NS(nodes) END_NS(jsxbin)
