//
// Created by Angelo DeLuca on 12/26/21.
//

#ifndef JSXBIN_DECOMPILER_THROWSTATEMENT_H
#define JSXBIN_DECOMPILER_THROWSTATEMENT_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class ThrowStatement : public AbstractNode {
    public:
        explicit ThrowStatement(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info lineInfo;
        AbstractNode *expression;
    };
}

#endif //JSXBIN_DECOMPILER_THROWSTATEMENT_H
