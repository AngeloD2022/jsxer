#include "jsxbin.h"
#include "util.h"
#include "nodes/Program.h"

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

void prepend_header(string& code) {
    string header = "/*\n"
                    "* Decompiled with Jsxbin Decompiler\n"
                    "* Version: 1.0.1\n"
                    "*/\n\n";
    code = header + code;
}

int jsxbin::decompile(const string& input, string& output) {
    using jsxbin::utils::string_strip_char;

    string compiled = input;

    string_strip_char(compiled, '\n');
    string_strip_char(compiled, '\r');
    string_strip_char(compiled, '\\');

    int start = -1;
    JsxbinVersion version;

    if ( !verifySignature(compiled.c_str(), &version, &start) ) {
        // TODO: Handle this properly
        fprintf(stderr, "JSXBIN signature verification failed!");
        output = "";
        return -3;
    }

    auto* reader = new Reader(compiled, version);
    reader->seek(start);

    // Parse into an Ast
    auto* program = new Program(*reader);
    program->parse();

    // Generate code from the ast
    output = program->to_string();
    prepend_header(output);

    return 0;
}