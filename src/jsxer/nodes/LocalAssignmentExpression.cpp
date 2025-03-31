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

            string value_assigned = literal.empty() ? b->get_op() : literal;
            result += var_name + ' ' + b->get_op_name() + "= " + value_assigned;

            return result;
        }

        string value_assigned = literal.empty() ? expression->to_string() : literal;
        result += var_name + " = " + value_assigned;

        return result;
    }

    void LocalAssignmentExpression::suppress_declarative_keyword(bool value) {
        declarative_suppress = value;
    }
}
