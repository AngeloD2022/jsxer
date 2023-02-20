#include "StatementList.h"


namespace jsxer::nodes {
    void StatementList::parse() {
        body = decoders::d_line_info(reader);

        length = decoders::d_length(reader);
        for (int i = 0; i < length; ++i) {
            statements.push_back(decoders::d_node(reader));
        }

        auto children = decoders::d_children(reader);
        statements.insert(statements.end(), children.begin(), children.end());
    }

    string StatementList::to_string() {
        string result;

        // A seemingly useless sorting step (by line number of statements) happens here (where this comment is) in the original project,
        // but I removed it. We'll see what happens when I test it...

        for (int i = 0; i < statements.size(); ++i) {
            string expression = statements[i]->to_string();

//        if (statements[i]->type() == NodeType::ExpressionStatement)
//            expression += ';';

            result += expression;

            if ((i + 1) < statements.size())
                result += '\n';
        }

        return body.lbl_statement() + result;
    }
}
