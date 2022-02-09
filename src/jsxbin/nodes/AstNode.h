#pragma once

#define istype(x, tname) strcmp(typeid(x).name(), tname) == 0

#include "../reader.h"

using namespace jsxbin;
using namespace std;

namespace jsxbin::nodes {
    class AstNode {
    public:
        explicit AstNode(Reader& reader) : reader(reader) {};
        virtual string jsx() = 0;
        virtual void parse() = 0;
    protected:
        Reader& reader;
    };
}
