//
// Created by Angelo DeLuca on 12/21/21.
//

#ifndef JSXBIN_DECOMPILER_FUNCTIONCALLEXPR_H
#define JSXBIN_DECOMPILER_FUNCTIONCALLEXPR_H

#include "AbstractNode.h"
#include "../decoders.h"
#include "ArgumentList.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class FunctionCallExpr : public AbstractNode {
    public:
        explicit FunctionCallExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        AbstractNode *function;
        AbstractNode *args;
        bool constructorCall;
    };
}

#endif //JSXBIN_DECOMPILER_FUNCTIONCALLEXPR_H
