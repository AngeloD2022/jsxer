#pragma once

#include "AstNode.h"
#include "../decoders.h"
#include <vector>

using namespace jsxbin;

namespace jsxbin { namespace nodes {
    class ArgumentList : public AstNode {
    public:
        explicit ArgumentList(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string to_string() override;

        vector<AstNode*> arguments;

    private:
        bool unkValue = false;

    };
} }
