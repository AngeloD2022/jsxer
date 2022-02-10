#include <iostream>
#include <string>
#include <fstream>

#include "jsxbin.h"

string get_filename(const char* path) {
    for(size_t i = strlen(path) - 1; i; --i)
    {
        if ((path[i] == '/') || (path[i] == '\\'))
        {
            return &path[i + 1];
        }
    }
    return path;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::string cli_path = argv[0];
        std::cout << "Usage: " << get_filename(cli_path.c_str()) << " <jsxbin path> <output path>" << std::endl;
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
