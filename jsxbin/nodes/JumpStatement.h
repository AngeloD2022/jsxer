//
// Created by asola on 12/21/2021.
//

#ifndef JSXBIN_DECOMPILER_JUMPSTATEMENT_H
#define JSXBIN_DECOMPILER_JUMPSTATEMENT_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class JumpStatement : public AbstractNode {
    public:
        explicit JumpStatement(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info labelInfo;
        string jmpLocation;
        bool breakStatement;
    };
}

#endif //JSXBIN_DECOMPILER_JUMPSTATEMENT_H
