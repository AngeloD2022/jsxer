//
// Created by Angelo DeLuca on 12/1/21.
//

#ifndef JSXBIN_DECOMPILER_ARRAYINDEXINGEXPR_H
#define JSXBIN_DECOMPILER_ARRAYINDEXINGEXPR_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class ArrayIndexingExpr : public AbstractNode {
    public:
        explicit ArrayIndexingExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override {
            decoders::d_ref(scanState); // <str, bool>
            AbstractNode *name = decoders::d_node(scanState);
            AbstractNode *expr = decoders::d_node(scanState);

            arrayName = name->jsx();
            expression = expr->jsx();
        }

        string jsx() override {
            return arrayName + '[' + expression + ']';
        }

    private:
        string arrayName;
        string expression;
    };
}

#endif //JSXBIN_DECOMPILER_ARRAYINDEXINGEXPR_H
