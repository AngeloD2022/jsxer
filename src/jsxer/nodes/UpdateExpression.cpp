#include "UpdateExpression.h"

namespace jsxer::nodes {
    void UpdateExpression::parse() {
        variable = decoders::d_node(reader);
        operation = decoders::d_literal_num(reader);
        postfix = reader.getBoolean();
    }

    string UpdateExpression::to_string() {
        string op = operation == 1 ? "++" : "--";
        return postfix ? variable->to_string() + op : op + variable->to_string();
    }
}
