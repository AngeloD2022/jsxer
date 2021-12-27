//
// Created by Angelo DeLuca on 12/26/21.
//

#ifndef JSXBIN_DECOMPILER_WITHSTATEMENT_H
#define JSXBIN_DECOMPILER_WITHSTATEMENT_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class WithStatement : public AbstractNode {
    public:
        explicit WithStatement(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info bodyInfo;
        AbstractNode *object;
    };
}

#endif //JSXBIN_DECOMPILER_WITHSTATEMENT_H
