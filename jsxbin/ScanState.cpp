//
// Created by Angelo DeLuca on 12/1/21.
//

#include "ScanState.h"

using namespace jsxbin;

ScanState::ScanState(const string &body, jsxbin_version version) {
    this->body = body;
    this->input_version = version;
}

jsxbin_version ScanState::get_version() {
    return input_version;
}

void ScanState::step() {
    index++;
}

char ScanState::pop() {
    char popped = body[index];
    index++;
    return popped;
}

char ScanState::peek(int ahead) {
    return body[index + ahead];
}

string ScanState::peek(int position, size_t length) {
    return body.substr(position, length);
}

int ScanState::get_node_depth() {
    if (node_depth_lvl == 0){
        update_node_depth();
    }

    return node_depth_lvl;
}

int ScanState::parse_node_depth() {
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

void ScanState::update_node_depth() {
    node_depth_lvl = parse_node_depth();
}

bool ScanState::decrement_node_depth() {
    if(get_node_depth() == 0)
        return false;

    node_depth_lvl--;
    return true;
}

string ScanState::get_symbol(string key) {
    return symbols.at(key);
}

void ScanState::add_symbol(string key, string value) {
    symbols.insert_or_assign(key, value);
}