#include "RegExpLiteral.h"

namespace jsxer::nodes {
    void RegExpLiteral::parse() {
        AstNode::parse();

        regex = utils::to_string(reader.getString());
        flags = utils::to_string(reader.getString());
    }

    string RegExpLiteral::to_string() {
        return '/' + regex + '/' + flags;
    }
}
