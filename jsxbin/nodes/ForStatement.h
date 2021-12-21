//
// Created by Angelo DeLuca on 12/20/21.
//

#ifndef JSXBIN_DECOMPILER_FORSTATEMENT_H
#define JSXBIN_DECOMPILER_FORSTATEMENT_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class ForStatement : public AbstractNode {
    public:
        explicit ForStatement(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info bodyInfo;
        AbstractNode *loopVar;
        string iteratorInitial;
        AbstractNode *upperBound;
        string stepSize;
        int length;
        string comparisonOperator;
    };

    class ForStatement2 : public AbstractNode {
    public:
        explicit ForStatement2(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info bodyInfo;
        AbstractNode *initial;
        AbstractNode *test;
        AbstractNode *update;
    };
}

#endif //JSXBIN_DECOMPILER_FORSTATEMENT_H
