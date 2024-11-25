#include "jsxer.h"
#include "util.h"
#include "nodes/Program.h"

#include <string>

void prepend_header(string& code, JsxbinVersion jsxbin_version, bool unblind) {
    string version;

    switch (jsxbin_version){
        case JsxbinVersion::v10:
            version = "1.0";
            break;
        case JsxbinVersion::v20:
            version = "2.0";
            break;
        case JsxbinVersion::v21:
            version = "2.1";
            break;
        default:
            version = "VERSION UNKNOWN";
    }

    string header = "/*\n"
                    "* Decompiled with Jsxer\n"
                    "* Version: " CONFIG_VERSION
                    "\n"
                    "* JSXBIN " + version + "\n";

    if (unblind) {
        header += "* Jsxblind Deobfuscation Enabled (EXPERIMENTAL)\n";
    }

    header += "*/\n\n";

    code = header + code;
}

int jsxer::decompile(const string& input, string& output, bool unblind) {
    auto reader = std::make_unique<Reader>(input, unblind);

    if (!reader->verifySignature()) {
        // TODO: Handle this properly
        printf("[!]: %s\n", "The input file has an invalid signature.");
        fprintf(stderr, "JSXBIN signature verification failed!");
        output = "";
        return -3;
    }

    // Parse into an Ast
    auto ast = std::make_unique<jsxer::nodes::Program>(*reader);
    ast->parse();

    // Generate code from the ast
    output = ast->to_string();
    prepend_header(output, reader->version(), unblind);

    return 0;
}

// for testing
int jsxer::decompile_test(const string& input, string& output, bool unblind) {
    auto reader = std::make_unique<Reader>(input, unblind);

    if (!reader->verifySignature()) {
        // TODO: Handle this properly
        fprintf(stderr, "JSXBIN signature verification failed!");
        output = "";
        return -3;
    }

    // Parse into an Ast
    auto ast = std::make_unique<jsxer::nodes::Program>(*reader);
    ast->parse();

    // Generate code from the ast
    output = ast->to_string();

    return 0;
}
