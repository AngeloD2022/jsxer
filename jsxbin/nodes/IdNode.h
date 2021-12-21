//
// Created by Angelo DeLuca on 12/21/21.
//

#ifndef JSXBIN_DECOMPILER_IDNODE_H
#define JSXBIN_DECOMPILER_IDNODE_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class IdNode : public AbstractNode {
    public:
        explicit IdNode(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        string id;
        bool unknown;
    };
}

#endif //JSXBIN_DECOMPILER_IDNODE_H
