//
// Created by Angelo DeLuca on 12/1/21.
//

#ifndef JSXBIN_DECOMPILER_ASSIGNMENTEXPR_H
#define JSXBIN_DECOMPILER_ASSIGNMENTEXPR_H

#include "AbstractNode.h"
#include "BinaryExpr.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {

    class AssignmentExpr : public AbstractNode {
    public:

        explicit AssignmentExpr(ScanState &scanState) : AbstractNode(scanState) {}

        void parse() override {
            var_name = decoders::d_ident(scanState);
            decoders::d_length(scanState);
            expression = decoders::d_node(scanState);
            literal = decoders::d_variant(scanState);
            shorthand = decoders::d_bool(scanState);
            declaration = decoders::d_bool(scanState);
        }

        string jsx() override {
            string result = declaration ? "var " : "";

            if (shorthand) {
                BinaryExpr *b = (BinaryExpr *)expression;

                // FIXME: i have a bad feeling about this one...
                string value_assigned = literal.empty() ? b->get_op() : literal;

                result += var_name + ' ' + b->get_op_name() + "= " + value_assigned;
            } else {
                string value_assigned = literal.empty() ? expression->jsx() : literal;
                result += var_name + " = " + value_assigned;
            }

            return result;
        }

    private:
        string var_name;
        AbstractNode *expression;
        string literal;
        bool shorthand;
        bool declaration;
    };
}

#endif //JSXBIN_DECOMPILER_ASSIGNMENTEXPR_H
