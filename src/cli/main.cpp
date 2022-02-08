#include <iostream>
#include <string>
#include <fstream>

#include "jsxbin.h"

int main(int argc, char* argv[]) {
    if (argc != 3){
        std::cout << "Usage: jsxbin_decompiler <jsxbin path> <output path>" << std::endl;
    } else {

        std::string input_path = argv[1];
        std::string output_path = argv[2];

        // read in the JSXBIN file contents...
        std::ifstream jsxbinFile(input_path);
        std::string content;
        content.assign(std::istreambuf_iterator<char>(jsxbinFile), std::istreambuf_iterator<char>());

        std::cout << std::endl << "Decompiling..." << std::endl;

        // begin de-compilation...
        std::string output;
        jsxbin::decompile(content, output);
        std::cout << "Finished." << std::endl;

        std::ofstream outfile(output_path);
        outfile << output;
        outfile.close();
    }

    return 0;
}
