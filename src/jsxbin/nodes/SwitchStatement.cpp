#include "SwitchStatement.h"

void SwitchStatement::parse() {
    lineInfo = decoders::d_line_info(reader);
    switchValue = decoders::d_node(reader);

    size_t len_cases = decoders::d_length(reader);
    for (int i = 0; i < len_cases; ++i){
        AstNode *node = decoders::d_node(reader);
        if (node != nullptr){
            cases.push_back(node);
        }
    }

    size_t len_implementations = decoders::d_length(reader);
    for (int i = 0; i < len_implementations; ++i){
        AstNode *node = decoders::d_node(reader);
        if (node != nullptr){
            implementations.push_back(node);
        }
    }

}

string SwitchStatement::jsx() {
    string result = "switch (" + switchValue->jsx() + ") { \n";

    for (int i = 0; i < cases.size(); ++i){

        vector<AstNode*> caseArgs = ((ArgumentList*)cases[i])->arguments;
        if (!caseArgs.empty()){
            for (AstNode* arg : caseArgs){
                result += "case " + arg->jsx() + ":\n";
            }
        } else {
            result += "default:\n";
        }

        // now for each case implementation...
        if (i < implementations.size()) {
            result += implementations[i]->jsx() + '\n';
        }
    }
    result += '}';

    return result;
}
