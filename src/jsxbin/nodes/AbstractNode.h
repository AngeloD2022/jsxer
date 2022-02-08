#pragma once

#define istype(x, tname) strcmp(typeid(x).name(), tname) == 0

#include "../ScanState.h"

using namespace jsxbin;
using namespace std;

namespace jsxbin::nodes {
    class AbstractNode {
    public:
        explicit AbstractNode(ScanState &scanState) : scanState(scanState) {};
        virtual string jsx() = 0;
        virtual void parse() = 0;
    protected:
        ScanState &scanState;
    };
}
