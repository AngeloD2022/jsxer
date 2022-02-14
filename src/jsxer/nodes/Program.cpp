#include "Program.h"

void Program::parse() {
    body = decoders::d_node(reader);
}

string Program::to_string() {
    return body->to_string();
}