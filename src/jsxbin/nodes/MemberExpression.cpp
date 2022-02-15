#include "MemberExpression.h"
#include "../util.h"

void MemberExpression::parse() {
    memberInfo = decoders::d_ref(reader);
    objInfo = decoders::d_node(reader);
}

string MemberExpression::to_string() {
    string result;

    string id_str = utils::to_string(memberInfo.id);

    // Check member validity...
    if (decoders::valid_id(id_str)) {
        result += ('.' + id_str);
    } else {
        result += '[';
        // check if ID can be converted to an integer...
        if(decoders::is_integer(id_str)) {
            result += id_str;
        } else {
            result += utils::to_string_literal(memberInfo.id);
        }
        result += ']';
    }

    return (objInfo == nullptr ? "" : objInfo->to_string()) + result;
}

