#include "WithStatement.h"

void WithStatement::parse() {
    bodyInfo = decoders::d_line_info(reader);
    object = decoders::d_node(reader);
}

string WithStatement::jsx() {
    return bodyInfo.lbl_statement() + "with (" + object->jsx() + ") {\n"+bodyInfo.create_body()+"\n}";
}
