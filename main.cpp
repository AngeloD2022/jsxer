#include <iostream>
#include <string>
#include <fstream>
#include "jsxbin/jsxbin.h"

int main() {
    std::string path = "/Users/angelodeluca/Downloads/Explode_Shape_Layers_3_v3.5.2-GFXDRUG.COM/Explode_Shape_Layers_3_v3.5.2/Explode Shape Layers.jsxbin";
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
