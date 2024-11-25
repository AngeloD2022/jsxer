#include "RegExpLiteral.h"
#include "../util.h"


namespace jsxer::nodes {
    void RegExpLiteral::parse() {
        regex = utils::to_string(reader.getString());
        flags = utils::to_string(reader.getString());
    }

    string RegExpLiteral::to_string() {
        return '/' + regex + '/' + flags;
    }
}
