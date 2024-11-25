#include "MemberExpression.h"
#include "../util.h"

namespace jsxer::nodes {
    void MemberExpression::parse() {
        memberInfo = decoders::d_literal_ref(reader);
        objInfo = decoders::d_node(reader);
    }

    string MemberExpression::to_string() {
        string result = (objInfo == nullptr ? "" : objInfo->to_string());

        if (decoders::is_integer(result) || (objInfo->type() == NodeType::BinaryExpression)) {
            result = '(' + result + ')';
        }

        if (objInfo->type() == NodeType::AssignmentExpression || objInfo->type() == NodeType::LocalAssignmentExpression)
            result = '(' + result + ')';

        // Check member validity...
        if (decoders::valid_id(memberInfo.id)) {
            result += '.' + utils::to_string(memberInfo.id);
            return result;
        }

        if (decoders::valid_xml_attribute(memberInfo.id)) {
            result += '.' + utils::to_string(memberInfo.id);
            return result;
        }

        result += '[';
        // check if ID can be converted to an integer...
        if (decoders::is_integer(memberInfo.id)) {
            result += utils::to_string(memberInfo.id);
        } else {
            result += utils::to_string_literal(memberInfo.id);
        }
        result += ']';


        return result;
    }
}
