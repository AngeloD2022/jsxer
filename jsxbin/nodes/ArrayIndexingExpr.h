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

        void parse() override;

        string jsx() override;

    private:
        string arrayName;
        string expression;
    };
}

#endif //JSXBIN_DECOMPILER_ARRAYINDEXINGEXPR_H
