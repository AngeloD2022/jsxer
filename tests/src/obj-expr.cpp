#include <jsxer.h>

const char compiled[] = "@JSXBIN@ES@2.0@MyBbyBn0ADJAnABjzDiHjJjYBfWzGiPjCjKjFjDjUCEzADFeFjXjCjFjUjWDARFFd\n"
                        "BFdCFdDFdEFdFfzBBEFeC2hdmY2kbmczBhQFFd2lRhAnfJGnAEXzJjTjUjSjJjOjHjJjGjZGfjzEiKi\n"
                        "TiPiOHfRBjBfffJHnAXEfjBf0DDByB";

int main() {
    string decompiled;
    int err = jsxer::decompile(compiled, decompiled);

    printf("--------------------------------------------------\n");
    printf("%s\n", decompiled.c_str());
    printf("--------------------------------------------------\n");

    return err;
}