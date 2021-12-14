//
// Created by Angelo DeLuca on 12/1/21.
//

#ifndef JSXBIN_DECOMPILER_ARGUMENTLIST_H
#define JSXBIN_DECOMPILER_ARGUMENTLIST_H

#pragma once

#include "AbstractNode.h"
#include "../decoders.h"
#include <vector>

using namespace jsxbin;

namespace jsxbin::nodes {

    class ArgumentList : public AbstractNode {
    public:
        explicit ArgumentList(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override {
            arguments = decoders::d_children(scanState);
            unkValue = decoders::d_bool(scanState);
        }

        string jsx() override {
            string result;
            for (int i = 0; i < arguments.size(); ++i) {
                result += arguments[i]->jsx() + (i + 1 == arguments.size() ? "": ", ");
            }

            return result;
        }

    private:
        vector<AbstractNode*> arguments;
        bool unkValue;

    };
}

#endif //JSXBIN_DECOMPILER_ARGUMENTLIST_H
