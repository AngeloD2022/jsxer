#pragma once

#include <memory>

#include "../reader.h"
#include "node-types.h"

using std::string;

using std::shared_ptr;
using std::make_shared;
using std::static_pointer_cast;

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
