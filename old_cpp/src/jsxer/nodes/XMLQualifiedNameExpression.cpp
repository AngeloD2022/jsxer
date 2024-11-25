#include "XMLQualifiedNameExpression.h"
#include "../util.h"

namespace jsxer::nodes {
    void XMLQualifiedNameExpression::parse() {
        namespaceObject = decoders::d_literal_ref(reader);
        object = decoders::d_node(reader);
        decoders::d_node(reader);
        decoders::d_node(reader);
        xmlId = decoders::d_sid(reader);
    }

    string XMLQualifiedNameExpression::to_string() {
        auto ns_id = utils::to_string(namespaceObject.id);
        string ns = namespaceObject.flag ? '@' + ns_id : ns_id;
        return object->to_string() + '.' + ns + "::" + xmlId;
    }
}
