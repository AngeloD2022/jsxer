//
// Created by asola on 12/21/2021.
//

#ifndef JSXBIN_DECOMPILER_MEMBEREXPR_H
#define JSXBIN_DECOMPILER_MEMBEREXPR_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class MemberExpr : public AbstractNode {
    public:
        explicit MemberExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::reference memberInfo;
        AbstractNode *objInfo;
    };
}

#endif //JSXBIN_DECOMPILER_MEMBEREXPR_H
