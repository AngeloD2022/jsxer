//
// Created by asola on 12/21/2021.
//

#include "MemberExpr.h"

void MemberExpr::parse() {
    memberInfo = decoders::d_ref(scanState);
    objInfo = decoders::d_node(scanState);
}

string MemberExpr::jsx() {
    // todo: complete implementation
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

