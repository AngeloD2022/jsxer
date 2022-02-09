#pragma once

#include <string>
#include <map>
#include "jsxbin.h"

using namespace std;

namespace jsxbin {
    class Reader {
    public:
        explicit Reader(const string& body, JsxbinVersion version);

        // meta...
        JsxbinVersion get_version();

        // tokens...
        void step();
        char pop();
        char peek(int ahead);
        void seek(int offset);

        // argument depth...
        int get_node_depth();
        bool decrement_node_depth();

        // symbol...
        string get_symbol(const string& key);
        void add_symbol(const string& key, string value);

    private:
        JsxbinVersion input_version;
        map<string, string> symbols;
        unsigned long index = 0;
        uint16_t node_depth = 0;
        string body;

        void update_node_depth();
        int parse_node_depth();
    };
}
