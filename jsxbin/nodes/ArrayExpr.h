//
// Created by Angelo DeLuca on 12/1/21.
//

#ifndef JSXBIN_DECOMPILER_ARRAYEXPR_H
#define JSXBIN_DECOMPILER_ARRAYEXPR_H

#include "AbstractNode.h"
#include "ArgumentList.h"
#include "../decoders.h"
#include <vector>

using namespace jsxbin;

namespace jsxbin::nodes {

    class ArrayExpr : public AbstractNode {
    public:
        explicit ArrayExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override {
            argumentList = (ArgumentList *) decoders::d_node(scanState);
        }

        string jsx() override {
            if(argumentList == nullptr){
                return "[]";
            }

            return '[' + argumentList->jsx() + ']';
        }

    private:
        ArgumentList* argumentList;

    };
}

#endif //JSXBIN_DECOMPILER_ARRAYEXPR_H
