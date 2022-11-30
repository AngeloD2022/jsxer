#include "util.h"
#include "deobfuscation.h"
#include "common.h"

using namespace jsxer::deob;

BEGIN_NS(jsxer)
BEGIN_NS(deob)


static const std::vector<string> OPERATORS {
        "=", "==", "!=", "!==", "===", "<=", ">=", ">", "<",
        "|=", "||=", "&&=", "&=", "^=", "??=",
        "|", "||", "&", "&&", "^", "??", "!", "?", ":",
        "instanceof", "typeof",
        "+", "+=",
        "-", "-=",
        "*", "*=",
        "%", "%=",
        "/", "/=",
        "**", "**=",
        "<<", "<<=",
        ">>", ">>=",
        ">>>", ">>>=",
        "~"
};

static const vector<char> PROHIBITED_CHARS {
    '=', '+', '<', '>', '-', '.', '*', '/', '|', '&', '?', '!', ':', '@', '~', '%', '^'
};

static const std::vector<uint16_t> PUNCT_CONNECTORS {
    0xFE33, 0xFE34, 0xFE4D, 0xFE4E, 0xFE4F, 0xFF3F, 0x203F, 0x2040, 0x2054
};

bool is_ECMA3_operator(const ByteString &symbol) {

    // if a symbol name is equivalent to an operator in ECMAScript 3, return true.
    string symstr = jsxer::utils::to_string(symbol);

    // check if the symbol name is contained within the list of operators...
    bool result = std::any_of(
            OPERATORS.begin(),
            OPERATORS.end(),
            [symstr](const string &op) {
                return symstr == op;
            }
    );

    return result;
}

bool is_compliant_name(const ByteString &symbol) {
    // check for anomalies in symbol naming that should only be possible with post-compilation binary changes.
    // see https://www-archive.mozilla.org/js/language/e262-3.pdf, section 7.6 (page 30)

    uint16_t first = symbol[0];

    // check if first character is numeric
    if (in_range_i(0x29, 0x40, first))
        return false;

    // check if the first character is a unicode combining diacritical mark
    if (in_range_i(0x0300, 0x036F, first))
        return false;

    // check if the first character is a unicode punctuation connector
    if (std::any_of(PUNCT_CONNECTORS.begin(), PUNCT_CONNECTORS.end(), [first](uint16_t p) {return first == p;}))
        return false;

    bool ok_chars = std::any_of(PROHIBITED_CHARS.begin(), PROHIBITED_CHARS.end(), [symbol] (char p) {
        return (bool) std::count(symbol.begin(), symbol.end(), (uint16_t)p);
    });

    return !ok_chars;
}

bool should_substitute(const ByteString &symbol, bool operator_ctx) {

    // if a symbol name is empty, return false.
    if (symbol.empty())
        return true;

//    if (is_ECMA3_operator(symbol) && operator_ctx)
//        return false;

    if (is_ECMA3_operator(symbol))
        return false;

    if (!is_compliant_name(symbol))
        return true;


    return false;
}

END_NS(deob)
END_NS(jsxer)