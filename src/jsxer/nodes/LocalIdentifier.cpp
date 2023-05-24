#include "LocalIdentifier.h"

namespace jsxer::nodes {
    void LocalIdentifier::parse() {
        AstNode::parse();

        reference = decoders::d_id_ref(reader);
        _type = decoders::d_length(reader);
    }

    string LocalIdentifier::to_string() {
        return utils::to_string(reference.id);
    }
}
