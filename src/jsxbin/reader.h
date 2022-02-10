#pragma once

#include "jsxbin.h"
#include "common.h"

#include <string>
#include <map>

using std::string;
using std::map;

BEGIN_NS(jsxbin)

class DataPool {
public:
    DataPool() = default;

    string get(const string& key);
    void add(const string& key, string value);
    void clear();

private:
    map<string, string> _pool;
};

class Reader {
public:
    explicit Reader(const string& body, JsxbinVersion version);

    // meta...
    JsxbinVersion version();

    // tokens...
    void step();
    char pop();
    char peek(int ahead);
    void seek(int offset);

    // argument depth...
    int get_node_depth();
    bool decrement_node_depth();

    // symbols map
    DataPool symbols;

private:
    JsxbinVersion input_version;
    unsigned long index = 0;
    uint16_t node_depth = 0;
    string body;

    void update_node_depth();
    int parse_node_depth();
};

END_NS(jsxbin)
