#pragma once

#include "common.h"
#include "util.h"


BEGIN_NS(jsxer)
BEGIN_NS(deob)

/// Determines if renaming is appropriate with symbols in JSXBIN files that are obfuscated with Jsxblind...
/// \param symbol the symbol name
/// \return
bool should_substitute(const ByteString& symbol, bool operator_ctx);

END_NS(deob)
END_NS(jsxer)
