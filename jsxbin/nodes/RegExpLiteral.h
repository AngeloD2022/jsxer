//
// Created by Angelo DeLuca on 12/26/21.
//

#ifndef JSXBIN_DECOMPILER_REGEXPLITERAL_H
#define JSXBIN_DECOMPILER_REGEXPLITERAL_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class RegExpLiteral : public AbstractNode {
    public:
        explicit RegExpLiteral(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        string regex;
        string flags;
    };
}

#endif //JSXBIN_DECOMPILER_REGEXPLITERAL_H
