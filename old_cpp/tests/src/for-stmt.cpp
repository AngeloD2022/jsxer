#include <jsxer.h>

const char compiled[] = "@JSXBIN@ES@2.0@MyBbyBn0ABKAbyCn0ABKCbyEn0ABOEbyFn0ABDFnAzEiMiCiMhRBfACzChdhdCQzA\n"
                        "DfjzBjSEfjzBjYFfQDfezEjUjIjJjTGfVzBjJHfyBnnbyIn0ABDInAzEiMiCiMhSIfBIRCSzBjKJyBn\n"
                        "dAftSzBjZKyBXzGjMjFjOjHjUjILfjzBjCMfnfttCzBhcNjFfVKfyBnnTJyBBtBBRCSHyBndAftSzBj\n"
                        "OOyBXLfjzBjBPfnfttCNVHfyBVOfyBnnTHyBBtAEH40BiAK4D0AiAJ4C0AiAO4B0AiAAEADByB";

int main() {
    string decompiled;
    int err = jsxer::decompile(compiled, decompiled);

    printf("--------------------------------------------------\n");
    printf("%s\n", decompiled.c_str());
    printf("--------------------------------------------------\n");

    return err;
}