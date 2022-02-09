#include "Program.h"

void Program::parse() {
    child = decoders::d_node(reader);
}

string Program::to_string() {
    return child->to_string();
}