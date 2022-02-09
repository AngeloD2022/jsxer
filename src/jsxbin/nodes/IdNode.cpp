#include "IdNode.h"

void IdNode::parse() {
    id = decoders::d_sid(reader);

    if (reader.get_version() >= JsxbinVersion::v20)
        unknown = decoders::d_bool(reader);
}

string IdNode::to_string() {
    return id;
}
