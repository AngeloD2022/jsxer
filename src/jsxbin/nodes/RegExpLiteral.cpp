#include "RegExpLiteral.h"

void RegExpLiteral::parse() {
    regex = decoders::d_string(reader);
    flags = decoders::d_string(reader);
}

string RegExpLiteral::jsx() {
    return '/' + regex + '/' + flags;
}
