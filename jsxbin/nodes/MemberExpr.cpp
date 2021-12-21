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
    return std::string();
}

