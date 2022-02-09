#pragma once

#include "../reader.h"

using std::string;

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class AstNode {
    public:
        explicit AstNode(Reader& reader) : reader(reader) {};
        virtual string to_string() = 0;
        virtual void parse() = 0;
    protected:
        Reader& reader;
    };
} }
