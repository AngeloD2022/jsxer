#include "LocalAssignmentExpression.h"


namespace jsxer::nodes {
    void LocalAssignmentExpression::parse() {
        var_name = decoders::d_sid(reader);
        unsigned int type = (unsigned int) decoders::d_length(reader);
        expression = decoders::d_node(reader);
        literal = decoders::d_variant(reader);
        shorthand = reader.getBoolean();
        declaration = reader.getBoolean();
    }

    string LocalAssignmentExpression::to_string() {
        string result = (declaration && !declarative_suppress) ? "var " : "";

        if (shorthand) {
            auto b = std::dynamic_pointer_cast<BinaryExpression>(expression);

            // FIXME: i have a bad feeling about this one...
            string value_assigned = literal.empty() ? b->get_op() : literal;
            string op = b->get_op_name();

            result += var_name;

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

//            result += var_name + ' ' + b->get_op_name() + "= " + value_assigned;
        } else {
            string value_assigned = literal.empty() ? expression->to_string() : literal;
            result += var_name + " = " + value_assigned;
        }

        return result;
    }

    void LocalAssignmentExpression::suppress_declarative_keyword(bool value) {
        declarative_suppress = value;
    }
}
