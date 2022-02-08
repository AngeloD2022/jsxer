#include "jsxbin.h"
#include "util.h"
#include "nodes/RootNode.h"

#include <string>
#include <regex>

using namespace std;
using namespace jsxbin::utils;

#define JSXBIN_SIGNATURE_V10 "@JSXBIN@ES@1.0@"
#define JSXBIN_SIGNATURE_V20 "@JSXBIN@ES@2.0@"
#define JSXBIN_SIGNATURE_V21 "@JSXBIN@ES@2.1@"

#define JSXBIN_SIGNATURE_LEN 15

bool verifySignature(const char* code, JsxbinVersion* version = nullptr, int* start = nullptr) {
    JsxbinVersion ver = JsxbinVersion::Invalid;

    if ( !strncmp(code, JSXBIN_SIGNATURE_V10, JSXBIN_SIGNATURE_LEN) ) {
        ver = JsxbinVersion::v10;
    } else if ( !strncmp(code, JSXBIN_SIGNATURE_V20, JSXBIN_SIGNATURE_LEN) ) {
        ver = JsxbinVersion::v20;
    } else if ( !strncmp(code, JSXBIN_SIGNATURE_V21, JSXBIN_SIGNATURE_LEN) ) {
        ver = JsxbinVersion::v21;
    } else {
        if (version) {
            *version = ver;
        }

        if (start) {
            *start = -1;
        }

        return false;
    }

    if (version) {
        *version = ver;
    }

    if (start) {
        *start = JSXBIN_SIGNATURE_LEN;
    }

    return true;
}

void append_header(string& code) {
    string header = "/*\n"
                    "* Decompiled with Jsxbin Decompiler\n"
                    "* Version: 1.0.1\n"
                    "*/\n\n";
    code = header + code;
}

int jsxbin::decompile(const string& input, string& output) {
    string compiled = input;

    string_replace(compiled, "\n", "");
    string_replace(compiled, "\r", "");
    string_replace(compiled, "\\", "");

    JsxbinVersion version;
    int start = -1;
    if ( !verifySignature(compiled.c_str(), &version, &start) ) {
        // TODO: Handle this properly
        fprintf(stderr, "JSXBIN signature verification failed!");
        output = "";
        return -3;
    }

    auto *scanState = new ScanState(compiled,
                                    (version == JsxbinVersion::v10)
                                        ? jsxbin_version::VERSION_1
                                        : jsxbin_version::VERSION_2);
    scanState->seek(start);

    // Start de-compilation.
    auto *root = new RootNode(*scanState);
    root->parse();

    output = root->jsx();
    append_header(output);

    return 0;
}