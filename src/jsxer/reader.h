#pragma once

#include "jsxer.h"
#include "common.h"
#include "deobfuscation.h"

#include <map>
#include <string>
#include <vector>
#include <memory>

using std::string;
using std::vector;
using std::map;

BEGIN_NS(jsxer)

#define JSXBIN_SIGNATURE_V10 "@JSXBIN@ES@1.0@"
#define JSXBIN_SIGNATURE_V20 "@JSXBIN@ES@2.0@"
#define JSXBIN_SIGNATURE_V21 "@JSXBIN@ES@2.1@"

#define JSXBIN_SIGNATURE_LEN 15

enum class ParseError : int {
    None = 0,

    InvalidVersion,
    ReachedEnd,
    DecodeError,
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

using OpVariant = std::shared_ptr<Variant>;

class Reader {
public:
    explicit Reader(const string& jsxbin, Options options);

    [[nodiscard]] JsxbinVersion version() const;
    [[nodiscard]] ParseError error() const;
    [[nodiscard]] size_t depth() const;

    [[nodiscard]] size_t parse_indent_level() const;
    [[nodiscard]] size_t dump_indent_level() const;
    [[nodiscard]] int parse_indent_size() const;
    [[nodiscard]] int dump_indent_size() const;
    [[nodiscard]] bool should_print_tree() const;

    bool verifySignature();

    Token get();
    Token peek(int offset = 0);
    void step(int offset = 1);

    Byte getByte();
    Number getNumber();
    ByteString getString();
    bool getBoolean();

    OpVariant getVariant();
    ByteString readSID(bool operator_context = false);
    ByteString readLiteral();

    void addSymbol(Number id, const ByteString& symbol);
    ByteString getSymbol(Number id);

    size_t get_node_depth();
    bool decrement_node_depth();

    void parse_indent_up();
    void parse_indent_down();

    void dump_indent_up();
    void dump_indent_down();

private:
    vector<Token> _data;
    size_t _parse_indent_level = 0;
    size_t _dump_indent_level = 0;
    int _parse_indent_size = 2;
    int _dump_indent_size = 2;
    size_t _start;
    size_t _end;
    size_t _cursor;
    size_t _depth;
    ParseError _error;
    JsxbinVersion _version;

    bool _unblind;
    bool _print_tree;
    deob::DeobfuscationContext deobfuscationContext;

    map<Number, ByteString> _symbols; // symbol pool

    void update_node_depth();
    int parse_node_depth();

    Token _next();
    static bool _ignorable(Token value);
};

END_NS(jsxbin)
