#pragma once

#include "AstNode.h"
#include "../decoders.h"

using namespace jsxbin;

namespace jsxbin::nodes {
    class IdNode : public AstNode {
    public:
        explicit IdNode(Reader& reader) : AstNode(reader) {}

        void parse() override;

        string jsx() override;

    private:
        string id;
        bool unknown = false;
    };
}
