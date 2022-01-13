//
// Created by Angelo DeLuca on 12/1/21.
//

#include "jsxbin.h"
#include "nodes/RootNode.h"

#include <string>
#include <algorithm>
#include <regex>

using namespace std;

const regex h_identify("^@JSXBIN@ES@([\\d.]+)@");
const regex h_replace("^@JSXBIN@ES@[\\d.]+@");

//void append_header(string &code){
//    // Append a header to the decompiler output with branding and version...
//    string header = "/**\n"
//                    " * File Generated With Studio7 DeJSX (TM)\n"
//                    " * Decompiler Version: 1.0.1\n"
//                    " */\n\n";
//    code = header + code;
//}

// copied+pasted from decoders.cpp
bool r_str(string &str, const string &from, const string &to) {
    size_t pos = str.find(from);
    while (pos != string::npos){
        str.replace(pos, from.length(), to);
        pos = str.find(from);
    }
    return true;
}

void jsxbin::decompile(const string &input, string &output) {

    // Normalize the input by removing line-breaks, carriage returns, and backslashes.
    string normalized = input;

    r_str(normalized, "\n", "");
    r_str(normalized, "\r", "");
    r_str(normalized, "\\", "");

    // Identify the JSXBIN Version.
    int version = 0;
    smatch matches;
    if(regex_search(normalized, matches, h_identify)){
        string match = matches[1].str();
        version = stoi(&match[0]);
    }
    // FIXME: This messes up a lot of things if not error-handled properly.

    // Remove the header from the normalized input.
    string body = regex_replace(normalized, h_replace, "");
    ScanState *scanState = new ScanState(body, version == 1? jsxbin_version::VERSION_1 : jsxbin_version::VERSION_2);

    // Start decompilation.
    RootNode *root = new RootNode(*scanState);
    root->parse();

    output = root->jsx();
//    append_header(output);
}