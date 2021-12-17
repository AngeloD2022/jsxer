//
// Created by Angelo DeLuca on 12/1/21.
//

#ifndef JSXBIN_DECOMPILER_ABSTRACTNODE_H
#define JSXBIN_DECOMPILER_ABSTRACTNODE_H


#include "../ScanState.h"

using namespace jsxbin;
using namespace std;

namespace jsxbin::nodes{

    class AbstractNode {
        // The universal features of each argument type...
    public:
        explicit AbstractNode(ScanState &scanState) : scanState(scanState) {};
        virtual string jsx() = 0;
        virtual void parse() = 0;
    protected:
        ScanState &scanState;
    };
}


#endif //JSXBIN_DECOMPILER_ABSTRACTNODE_H
