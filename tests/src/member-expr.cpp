#include <jsxer.h>

const char compiled[] = "@JSXBIN@ES@2.0@MyBbyBn0AIJBnAXzB2jEhHBfjzBjRCfJCnAXzB2lNmeDfjCfJDnAXzBhQEfjzBjBF\n"
                        "fJEnAXzHhShVhVhShThWjQGfjzBjCHfJFnAXzEjQjSjPjQIfjzBjYJfJGnAXzGhEjJjEjIjEjHKfjJf\n"
                        "JHnAXzGifjTjJjGjIjJLfjJfJInAEXzIjUjPiTjUjSjJjOjHMfFd2nIDnf0DzANByB";

int main() {
    string decompiled;
    int err = jsxer::decompile(compiled, decompiled);

    printf("--------------------------------------------------\n");
    printf("%s\n", decompiled.c_str());
    printf("--------------------------------------------------\n");

    return err;
}