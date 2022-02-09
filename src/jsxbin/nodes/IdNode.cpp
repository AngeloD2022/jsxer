#include "IdNode.h"

void IdNode::parse() {
    id = decoders::d_ident(reader);

    if (reader.get_version() >= JsxbinVersion::v20)
        unknown = decoders::d_bool(reader);
}

string IdNode::jsx() {
    return id;
}
