//
// Created by Angelo DeLuca on 12/26/21.
//

#ifndef JSXBIN_DECOMPILER_TRYSTATEMENT_H
#define JSXBIN_DECOMPILER_TRYSTATEMENT_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class TryStatement : public AbstractNode {
    public:
        explicit TryStatement(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:

        struct tc_layer {
            string arg;
            AbstractNode *exceptionFilter;
            AbstractNode *catchBlock;
        };

        decoders::line_info tryBlock;
        AbstractNode *finallyBlock;
        vector<tc_layer> layers;
        int length;
    };
}

#endif //JSXBIN_DECOMPILER_TRYSTATEMENT_H
