#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class FunctionDeclaration : public AstNode {
    public:
        explicit FunctionDeclaration(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        decoders::line_info bodyInfo;
        decoders::function_signature signature;
        int type;
    };
}
