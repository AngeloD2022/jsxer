#include <iostream>
#include <string>
#include <fstream>
#include "jsxbin/jsxbin.h"

int main() {
    std::string path = "/Users/angelodeluca/Downloads/sliced_box_v3.25/Sliced Box.jsxbin";
//    std::cout << "Enter the .jsxbin file path to decompile: " << std::endl;
//    std::cin >> path;

    // read in the JSXBIN file contents...
    std::ifstream jsxbinFile(path);
    std::string content;
    content.assign(std::istreambuf_iterator<char>(jsxbinFile), std::istreambuf_iterator<char>());

    std::cout << std::endl << "Decompiling..." << std::endl;

    // begin decompilation...
    std::string output;
    jsxbin::decompile(content, output);

    std::cout << "Finished." << std::endl;

    std::ofstream outfile("output.jsx");
    outfile << output;
    outfile.close();

    return 0;
}
