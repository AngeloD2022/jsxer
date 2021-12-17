//
// Created by Angelo DeLuca on 12/1/21.
//

#ifndef JSXBIN_DECOMPILER_SCANSTATE_H
#define JSXBIN_DECOMPILER_SCANSTATE_H

#include <string>
#include <map>
#include "jsxbin.h"


using namespace std;

namespace jsxbin{

    class ScanState {

    public:

        explicit ScanState(const string &body, jsxbin_version version);

        // meta...
        jsxbin_version get_version();

        // tokens...
        void step();
        char pop();
        char peek(int ahead);
        string peek(int position, size_t length);

        // argument depth...
        int get_node_depth();
        bool decrement_node_depth();

        // symbol...
        string get_symbol(string key);
        void add_symbol(string key, string value);

    private:
        jsxbin_version input_version;
        map<string, string> symbols;
        unsigned long index = 0;
        uint16_t node_depth_lvl= 0;
        string body;

        void update_node_depth();
        int parse_node_depth();
    };
}


#endif //JSXBIN_DECOMPILER_SCANSTATE_H
