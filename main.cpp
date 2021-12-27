#include <iostream>
#include <string>
#include <fstream>
#include "jsxbin/jsxbin.h"

int main() {
    std::string path;
    std::cout << "Enter the .jsxbin file path to decompile: " << std::endl;
    std::cin >> path;

    // read in the JSXBIN file contents...
    std::ifstream jsxbinFile(path);
    std::string content;
    content.assign(std::istreambuf_iterator<char>(jsxbinFile), std::istreambuf_iterator<char>());

    std::cout << std::endl << "Decompiling...";

    // begin decompilation...
    std::string output;
    jsxbin::decompile(path, output);

    return 0;
}
