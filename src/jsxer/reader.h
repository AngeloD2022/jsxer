#pragma once

#include "jsxer.h"
#include "common.h"

#include <string>
#include <map>
#include <vector>

using std::string;
using std::vector;
using std::map;

typedef uint8_t Token;

typedef uint8_t Byte;
typedef double Number;

using String = std::string;
using Bytes = std::vector<uint8_t>;
using ByteString = std::vector<uint16_t>;

BEGIN_NS(jsxer)

#define JSXBIN_SIGNATURE_V10 "@JSXBIN@ES@1.0@"
#define JSXBIN_SIGNATURE_V20 "@JSXBIN@ES@2.0@"
#define JSXBIN_SIGNATURE_V21 "@JSXBIN@ES@2.1@"

#define JSXBIN_SIGNATURE_LEN 15

enum class ParseError : int {
    None = 0,
    InvalidVersion,
    ReachedEnd = 51,
    Error8 = 8,
};

enum class VariantType : int {
    None = -1,

    Undefined = 0,
    Null = 1,
    Boolean = 2,
    Number = 3,
    String = 4,
};

class Variant {
public:
    Variant();

    void doErase();

    void setNull();

    void setString(const ByteString& value);

    void setBool(bool value);

    void setDouble(double value);

    String toString();

private:
    VariantType _type;
    struct ValueType {
        bool _bool;
        double _double;
        ByteString _string;
    } _value;
};

class Reader {
public:
    explicit Reader(const string& jsxbin);

    JsxbinVersion version() const;
    ParseError error() const;
    size_t depth() const;

    bool verifySignature();

    Token get();
    Token peek(int offset = 0);
    void step(int offset = 1);

    Byte getByte();
    Number getNumber();
    ByteString getString();
    bool getBoolean();
    Variant* getVariant();
    ByteString readSID();

    void addSymbol(Number id, const ByteString& symbol);
    ByteString getSymbol(Number id);

    size_t get_node_depth();
    bool decrement_node_depth();

private:
    vector<Token> _data;
    size_t _start;
    size_t _end;
    size_t _cursor;
    size_t _depth;
    ParseError _error;
    JsxbinVersion _version;

    map<Number, ByteString> _symbols;

    void update_node_depth();
    int parse_node_depth();

    Token _next();
    static bool _ignorable(Token value);
};

END_NS(jsxbin)
