#include "WithStatement.h"

void WithStatement::parse() {
    bodyInfo = decoders::d_linfo(scanState);
    object = decoders::d_node(scanState);
}

string WithStatement::jsx() {
    return bodyInfo.lbl_statement() + "with (" + object->jsx() + ") {\n"+bodyInfo.create_body()+"\n}";
}
