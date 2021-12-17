//
// Created by Angelo DeLuca on 12/16/21.
//

#ifndef JSXBIN_DECOMPILER_DEBUGGERSTATEMENT_H
#define JSXBIN_DECOMPILER_DEBUGGERSTATEMENT_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class DebuggerStatement : public AbstractNode {
    public:
        explicit DebuggerStatement(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info lineInfo;
    };
}

#endif //JSXBIN_DECOMPILER_DEBUGGERSTATEMENT_H
