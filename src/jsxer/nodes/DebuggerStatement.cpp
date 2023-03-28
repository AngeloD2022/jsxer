#include "DebuggerStatement.h"

namespace jsxer::nodes {
    void DebuggerStatement::parse() {
        print_tree_node(reader, "DebuggerStatement");

        lineInfo = decoders::d_line_info(reader);
    }

    string DebuggerStatement::to_string() {
        return lineInfo.lbl_statement() + "debugger";
    }
}
