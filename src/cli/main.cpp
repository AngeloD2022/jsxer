#include <iostream>
#include <string>
#include <fstream>

#include "jsxer.h"

string get_filename(const char* path) {
    for(size_t i = strlen(path) - 1; i; --i)
    {
        if ((path[i] == '/') || (path[i] == '\\')) {
            return &path[i + 1];
        }
    }
    return path;
}

void print_usage(std::string cli_path){
    std::cout << "Usage: " << get_filename(cli_path.c_str()) << " <jsxbin path> <output path> [--jsxblind]" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 3 || argc > 4) {
        print_usage(argv[0]);
        exit(0);
    } else {
        std::string input_path = argv[1];
        std::string output_path = argv[2];

        // read in the JSXBIN file contents...
        std::ifstream jsxbinFile(input_path);
        std::string content;
        content.assign(std::istreambuf_iterator<char>(jsxbinFile), std::istreambuf_iterator<char>());

        std::cout << "[i] Decompiling..." << std::endl;

        // begin de-compilation...
        std::string output;

        if (argc == 4) {
            if (strcmp(argv[3], "--jsxblind") == 0) {
                std::cout << "[+] Jsxblind deobfuscation enabled!" << std::endl;
                jsxer::decompile(content, output, true);
            } else {
                print_usage(argv[0]);
                exit(0);
            }
        } else {
            jsxer::decompile(content, output);
        }
        std::cout << "[i] Finished." << std::endl;

        std::ofstream outfile(output_path);
        outfile << output;
        outfile.close();
    }

    return 0;
}
