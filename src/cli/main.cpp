#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>

#include "jsxer.h"

inline std::string read_file(const std::string& path) {
    std::ostringstream buf;
    std::ifstream input (path.c_str());
    buf << input.rdbuf();
    return buf.str();
}

string get_filename(const char* path) {
    for(size_t i = strlen(path) - 1; i; --i) {
        if ((path[i] == '/') || (path[i] == '\\')) {
            return &path[i + 1];
        }
    }
    return path;
}

void print_usage(const std::string& cli_path) {
    std::cout << "Usage: " << get_filename(cli_path.c_str()) << " <jsxbin path> <output path> [--unblind]" << std::endl;
    exit(0);
}

int main(int argc, char* argv[]) {
    if (argc < 3 || argc > 4) {
        print_usage(argv[0]);
        exit(0);
    } else {
        std::string input_path = argv[1];
        std::string output_path = argv[2];

        // read in the JSXBIN file contents...
        std::string content = read_file(input_path);
        std::cout << "[i] Decompiling..." << std::endl;

        // begin de-compilation...
        std::string output;
        bool unblind = false;

        if (argc == 4) {
            if (strcmp(argv[3], "--unblind") == 0) {
                std::cout << "[+] Jsxblind deobfuscation enabled!" << std::endl;
                unblind = true;
            } else {
                print_usage(argv[0]);
                exit(0);
            }
        }
        jsxer::decompile(content, output, unblind);
        std::cout << "[i] Finished." << std::endl;

        std::ofstream outfile(output_path);
        outfile << output;
        outfile.close();
    }

    return 0;
}
