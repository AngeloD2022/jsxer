#include "LocalIdentifier.h"

void LocalIdentifier::parse() {
    reference = decoders::d_ref(reader);
    _type = decoders::d_length(reader);
}

string LocalIdentifier::to_string() {
    return reference.id;
}
