#include <jsxer.h>

const char compiled[] = "@JSXBIN@ES@2.1@MyBbyBn0ACJAnASzBjWByBnd8lYmNmRkUlLiRiXiAftJBnAEjzFjQjSjJjOjUCfRBVBfyBffABB40BiAABAzADByB";

int main() {
    string decompiled;
    int err = jsxer::decompile(compiled, decompiled);

    printf("--------------------------------------------------\n");
    printf("%s\n", decompiled.c_str());
    printf("--------------------------------------------------\n");

    return err;
}