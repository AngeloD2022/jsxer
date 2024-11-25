#pragma once

#include "common.h"
#include "util.h"

#include <map>

BEGIN_NS(jsxer)
BEGIN_NS(deob)

struct DeobfuscationContext {
    // making this a struct in an attempt to future-proof, but maybe this should be a class?
    bool empty_id_reserved = false;
};

/// Determines if renaming is appropriate with symbols in JSXBIN files that are obfuscated with Jsxblind...
/// \param symbol the symbol name
/// \return
bool jsxblind_should_substitute(DeobfuscationContext& context, const ByteString& symbol, bool operator_ctx);

END_NS(deob)
END_NS(jsxer)
