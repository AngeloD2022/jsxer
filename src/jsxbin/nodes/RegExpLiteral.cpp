#include "RegExpLiteral.h"

void RegExpLiteral::parse() {
    regex = decoders::d_string(scanState);
    flags = decoders::d_string(scanState);
}

string RegExpLiteral::jsx() {
    return '/' + regex + '/' + flags;
}
