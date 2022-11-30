#pragma once

#include "common.h"
#include "util.h"

using namespace std;

BEGIN_NS(jsxer)
BEGIN_NS(deob)

//class Deobfuscation {
//public:
//    explicit Deobfuscation(vector<Number> *reserved_ids);
//
//    bool should_substitute(Number id, const ByteString& symbol);
//
//private:
//    vector<Number> *_reserved_ids;
//};

/// Determines if renaming is appropriate with symbols in JSXBIN files that are obfuscated with Jsxblind...
/// \param symbol the symbol name
/// \return
bool should_substitute(const ByteString& symbol, bool operator_ctx);

END_NS(deob)
END_NS(jsxer)