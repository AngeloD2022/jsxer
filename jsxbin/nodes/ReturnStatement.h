//
// Created by Angelo DeLuca on 12/26/21.
//

#ifndef JSXBIN_DECOMPILER_RETURNSTATEMENT_H
#define JSXBIN_DECOMPILER_RETURNSTATEMENT_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class ReturnStatement : public AbstractNode {
    public:
        explicit ReturnStatement(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info lineInfo;
        AbstractNode *expression;
    };
}

#endif //JSXBIN_DECOMPILER_RETURNSTATEMENT_H
