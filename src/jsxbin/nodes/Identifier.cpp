#include "Identifier.h"

void Identifier::parse() {
    id = decoders::d_sid(reader);

    if (reader.get_version() >= JsxbinVersion::v20)
        unknown = decoders::d_bool(reader);
}

string Identifier::to_string() {
    return id;
}
