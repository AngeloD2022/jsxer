//
// Created by Angelo DeLuca on 12/26/21.
//

#ifndef JSXBIN_DECOMPILER_OBJECTEXPR_H
#define JSXBIN_DECOMPILER_OBJECTEXPR_H

#include "AbstractNode.h"
#include "../decoders.h"
#include <algorithm>

using namespace jsxbin;

namespace jsxbin::nodes {

    class ObjectExpr : public AbstractNode {
    public:
        explicit ObjectExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        string objectId;
        map<string, AbstractNode*> properties;
    };
}

#endif //JSXBIN_DECOMPILER_OBJECTEXPR_H
