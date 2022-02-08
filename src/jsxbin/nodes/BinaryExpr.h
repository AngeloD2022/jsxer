#pragma once

#include "AbstractNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class BinaryExpr : public AbstractNode {
    public:
        explicit BinaryExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override;

        string jsx() override;

        string get_op(){
            return this->op;
        }

        string get_op_name() {
            return this->op_name;
        }

    private:
        string op_name;
        string op;
        AbstractNode* left;
        AbstractNode* right;
        string literalLeft;
        string literalRight;
        string create_expr(const string &literal, AbstractNode *exprNode);
    };
}
