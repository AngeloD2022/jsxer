#include "IdNode.h"

void IdNode::parse() {
    id = decoders::d_ident(scanState);

    if (scanState.get_version() == jsxbin_version::VERSION_2)
        unknown = decoders::d_bool(scanState);
}

string IdNode::jsx() {
    return id;
}
