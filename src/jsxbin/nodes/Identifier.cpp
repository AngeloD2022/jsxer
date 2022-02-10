#include "Identifier.h"

void Identifier::parse() {
    id = decoders::d_sid(reader);

    if (reader.version() >= JsxbinVersion::v20)
        unknown = decoders::d_bool(reader);
}

string Identifier::to_string() {
    return id;
}
