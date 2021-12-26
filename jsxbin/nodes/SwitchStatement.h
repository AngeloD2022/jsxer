//
// Created by Angelo DeLuca on 12/26/21.
//

#ifndef JSXBIN_DECOMPILER_SWITCHSTATEMENT_H
#define JSXBIN_DECOMPILER_SWITCHSTATEMENT_H

#include "AbstractNode.h"
#include "../decoders.h"
#include "ArgumentList.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class SwitchStatement : public AbstractNode {
    public:
        explicit SwitchStatement(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info lineInfo;
        AbstractNode *switchValue;
        vector<AbstractNode*> cases;
        vector<AbstractNode*> implementations;
    };
}

#endif //JSXBIN_DECOMPILER_SWITCHSTATEMENT_H
