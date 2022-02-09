#include "reader.h"

using namespace jsxbin;

Reader::Reader(const string &body, JsxbinVersion version) {
    this->body = body;
    this->input_version = version;
}

JsxbinVersion Reader::get_version() {
    return input_version;
}

void Reader::step() {
    index++;
}

char Reader::pop() {
    return body[index++];
}

char Reader::peek(int ahead) {
    return body[index + ahead];
}

void Reader::seek(int offset) {
    index += offset;
}

int Reader::get_node_depth() {
    if (node_depth == 0){
        update_node_depth();
    }

    return node_depth;
}

int Reader::parse_node_depth() {
    char current = peek(0);

    if (current == 'A') {
        step();
        return 1;

    } else if (current == '0') {
        step();
        int levels = pop() - 0x3f;

        if (levels > 0x1b) {
            return levels + parse_node_depth();
        }
        return levels;

    }

    return 0;
}

void Reader::update_node_depth() {
    node_depth = parse_node_depth();
}

bool Reader::decrement_node_depth() {
    if(get_node_depth() == 0)
        return false;

    node_depth--;
    return true;
}

string Reader::get_symbol(const string& key) {
    return symbols.at(key);
}

void Reader::add_symbol(const string& key, string value) {
    symbols.insert_or_assign(key, value);
}