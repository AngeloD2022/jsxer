#include "jsxer.h"
#include "util.h"
#include "nodes/Program.h"

#include <string>

using namespace std;

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

void prepend_header(string& code, bool deobfuscation) {
    string header = "/*\n"
                    "* Decompiled with Jsxbin Decompiler\n"
                    "* Version: " CONFIG_VERSION "\n"
                    "*/\n\n";

    if (deobfuscation){
        header = "/*\n"
                 "* Decompiled with Jsxbin Decompiler\n"
                 "* Version: " CONFIG_VERSION "\n"
                 "* Jsxblind Deobfuscation Enabled (EXPERIMENTAL)\n"
                 "*/\n\n";
    }

    code = header + code;
}

int jsxer::decompile(const string& input, string& output, bool jsxblind_deobfuscate) {
    Reader reader(input, jsxblind_deobfuscate);

    if (!reader.verifySignature()) {
        // TODO: Handle this properly
        fprintf(stderr, "JSXBIN signature verification failed!");
        output = "";
        return -3;
    }

    // Parse into an Ast
    Program ast(reader);
    ast.parse();

    // Generate code from the ast
    output = ast.to_string();
    prepend_header(output, jsxblind_deobfuscate);

    return 0;
}