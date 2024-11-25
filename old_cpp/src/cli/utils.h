#include <filesystem>
#include <fstream>
#include <string>
#include <iterator>

namespace fs = std::filesystem;

namespace utils {
    std::vector<unsigned char> ReadFileContents(const fs::path& path) {
        //  std::ios::binary    -> makes it read as binary
        std::ifstream f(path, std::ios::binary);

        // Stop eating new lines in binary mode!!!
        f.unsetf(std::ios::skipws);

        // move cursor to start
        f.seekg(0, std::ios::beg);

        return {
            std::istream_iterator<unsigned char>(f),
            std::istream_iterator<unsigned char>()
        };
    }

    size_t WriteFileContents(const fs::path& path, const std::string& contents) {
        //  std::ios::binary    -> makes it read as binary
        std::ofstream f(path);

        // move cursor to start
        f << contents;
        f.close();

        return contents.size();
    }
}