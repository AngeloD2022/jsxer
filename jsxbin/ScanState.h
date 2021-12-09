//
// Created by Angelo DeLuca on 12/1/21.
//

#ifndef JSXBIN_DECOMPILER_SCANSTATE_H
#define JSXBIN_DECOMPILER_SCANSTATE_H

#include <string>


using namespace std;

namespace jsxbin{

    class ScanState {

    public:

        explicit ScanState(const string &body);

        // change...
        void step();
        char pop();

        // no change...
        char peek(int ahead);
        string peek(int position, size_t length);

        // node depth...
        int get_node_depth();
        bool decrement_node_depth();

    private:
        unsigned long index = 0;
        uint16_t node_depth_lvl= 0;
        string body;

        void update_node_depth();
        int parse_node_depth();
    };
}


#endif //JSXBIN_DECOMPILER_SCANSTATE_H
