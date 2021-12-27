//
// Created by Angelo DeLuca on 12/26/21.
//

#ifndef JSXBIN_DECOMPILER_WHILESTATEMENT_H
#define JSXBIN_DECOMPILER_WHILESTATEMENT_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class WhileStatement : public AbstractNode {
    public:
        explicit WhileStatement(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info bodyInfo;
        AbstractNode *condition;
    };
}

#endif //JSXBIN_DECOMPILER_WHILESTATEMENT_H
