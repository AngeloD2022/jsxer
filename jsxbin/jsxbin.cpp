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


void jsxbin::decompile(const string &input, string &output) {

    // Normalize the input by removing line-breaks, carriage returns, and backslashes.
    string normalized;
    remove_copy(input.begin(), input.end(), back_inserter(normalized), '\n');
    remove_copy(normalized.begin(), normalized.end(), back_inserter(normalized), '\r');
    remove_copy(normalized.begin(), normalized.end(), back_inserter(normalized), '\\');

    // Identify the JSXBIN Version.
    int version = 0;
    smatch matches;
    if(regex_search(normalized, matches, h_identify)){
        string match = matches[1].str();
        version = stoi(&match[0]);
    }
    // TODO: This is unsafe. Add error handling.

    // Remove the header from the normalized input.
    string body = regex_replace(normalized, h_replace, "");
    ScanState *scanState = new ScanState(body, version == 1? jsxbin_version::VERSION_1 : jsxbin_version::VERSION_2);

    // Start decompilation.
    RootNode *root = new RootNode(*scanState);

    output = root->jsx();
}