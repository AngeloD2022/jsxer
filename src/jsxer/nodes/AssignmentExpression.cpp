#include "AssignmentExpression.h"

namespace jsxer::nodes {
    void AssignmentExpression::parse() {
        variable = decoders::d_node(reader);
        expression = decoders::d_node(reader);
        literal = decoders::d_variant(reader);
        shorthand = reader.getBoolean();
    }

    string AssignmentExpression::to_string() {
        if (shorthand) {
            auto expr = std::dynamic_pointer_cast<BinaryExpression>(expression);
            string value_assigned = literal.empty() ? expr->get_op() : literal;

            return variable->to_string() + ' ' + expr->get_op_name() + "= " + value_assigned;
        }

        string value_assigned = literal.empty() ? expression->to_string() : literal;
        return variable->to_string() + " = " + value_assigned;

    }
}
