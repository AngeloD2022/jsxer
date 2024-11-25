#include "Identifier.h"

namespace jsxer::nodes {
    void Identifier::parse() {
        id = decoders::d_sid(reader);

        if (reader.version() >= JsxbinVersion::v20)
            unknown = reader.getBoolean();
    }

    string Identifier::to_string() {
        return id;
    }
}
