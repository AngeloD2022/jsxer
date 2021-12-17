//
// Created by Angelo DeLuca on 12/16/21.
//

#ifndef JSXBIN_DECOMPILER_CONSTDECLARATION_H
#define JSXBIN_DECOMPILER_CONSTDECLARATION_H

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class ConstDeclaration : public AbstractNode {
    public:
        explicit ConstDeclaration(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

    private:
        string name;
        int length;
        AbstractNode *expression;
        string literal;
        bool boolean_1;
        bool boolean_2;
    };
}

#endif //JSXBIN_DECOMPILER_CONSTDECLARATION_H
