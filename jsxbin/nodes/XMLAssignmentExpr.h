//
// Created by Angelo DeLuca on 12/26/21.
//

#ifndef JSXBIN_DECOMPILER_XMLASSIGNMENTEXPR_H
#define JSXBIN_DECOMPILER_XMLASSIGNMENTEXPR_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class XMLAssignmentExpr : public AbstractNode {
    public:
        explicit XMLAssignmentExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        map<AbstractNode*, int> children;


    };
}

#endif //JSXBIN_DECOMPILER_XMLASSIGNMENTEXPR_H
