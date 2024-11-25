#include <string>
#include <iostream>
#include <filesystem>

#include <CLI/App.hpp>
#include <CLI/Formatter.hpp>    // DON'T remove
#include <CLI/Config.hpp>       // DON'T remove

#include <jsxer.h>

#include "./utils.h"

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    CLI::App cli{
        "JSXER - A fast and accurate JSXBIN decompiler.\n"
        "Written by Angelo DeLuca and contributors.\n",
    };
    cli.set_version_flag("-v,--version", CONFIG_VERSION);

    // cli flag variables
    bool unblind = false;
//    bool verbose = false;
    std::string input;
    std::string output;

    // cli building
    auto output_option = cli.add_option("-o,--output",
                   output,
                   "Output path for the decompiled file");
    cli.add_flag("-b,--unblind",
                   unblind,
                   "Try renaming symbols which are obfuscated by 'JsxBlind' (experimental)");
//    cli.add_flag("-v,--verbose",
//                   verbose,
//                   "Display verbose log");

    cli.add_option("input",
                   input,
                   "Name of file to read"
    )->check(CLI::ExistingFile)->required();

    // cli parsing
    try {
        cli.parse(argc, argv);
    } catch(const CLI::ParseError &e) {
        return cli.exit(e);
    }

    // process
    auto input_path = fs::path(input);

    fs::path output_path = !bool(*output_option)
        ? input_path.parent_path() / (input_path.stem().string() + ".jsx")
        : fs::path(output);

    if (!bool(*output_option) && fs::exists(output_path.parent_path())) {
        fs::create_directories(output_path.parent_path());
    }

    // read in the JSXBIN file contents...
    auto contents = utils::ReadFileContents(input_path);
    auto contents_str = std::string(contents.begin(), contents.end());

    // begin de-compilation...
    std::string decompiled;
    std::cout << "[i] Decompiling..." << std::endl;
    jsxer::decompile(contents_str, decompiled, unblind);
    std::cout << "[i] Finished." << std::endl;

    utils::WriteFileContents(output_path, decompiled);

    return 0;
}
