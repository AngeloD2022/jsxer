#include "MemberExpr.h"

void MemberExpr::parse() {
    memberInfo = decoders::d_ref(reader);
    objInfo = decoders::d_node(reader);
}

string MemberExpr::jsx() {
    string result;

    // Check member validity...
    if (decoders::valid_id(memberInfo.id)){
        result = "." + memberInfo.id;
    } else {

        // check if ID can be converted to an integer...
        if(decoders::is_integer(memberInfo.id)){
            result = '[' + memberInfo.id + ']';
        } else {
            result = "[\"" + memberInfo.id + "\"]";
        }
    }

    return (objInfo == nullptr ? "" : objInfo->jsx()) + result;
}

