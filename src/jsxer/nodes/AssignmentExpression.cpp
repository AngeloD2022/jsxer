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
            string op = expr->get_op_name();

            string result = variable->to_string();

            bool is_negative = value_assigned[0] == '-';

            // attempt to simplify the shorthand update expression with + and -...
            if (op == "+" || op == "-") {
                if (is_negative) {
                    value_assigned = value_assigned.substr(1);
                    op = op == "+" ? "-" : "+";
                }
                if (value_assigned == "1") {
                    return result + op + op;
                }
            }
            return result + ' ' + op + "= " + value_assigned;

        } else {
            string value_assigned = literal.empty() ? expression->to_string() : literal;
            return variable->to_string() + " = " + value_assigned;
        }
    }
}
