//
// Created by Angelo DeLuca on 12/1/21.
//

#include "decoders.h"
#include <string>
#include <vector>

#define iscapital(x) x - 0x41 <= 0x19

using namespace jsxbin::decoders;

AbstractNode *d_node(ScanState &scanState) {
    return nullptr;
}

string dnumber_primitive(ScanState &scanState, int length, bool negative) {
    // probably more efficient?
    byte bytes[length];
    for (int i = 0; i < length; ++i) {
        bytes[i] = d_byte(scanState);
    }

    // copy ambiguous type into buffer...
    void *buf = malloc(length);
    memcpy(&buf, bytes, length);

    short sign = negative ? -1 : 1;

    // using the length, return the appropriate interpretation of the value...
    switch (length) {
        case 8:
            // result is double...
            return to_string(reinterpret_cast<double &>(buf) * sign);
        case 4:
            // result is an integer...
            return to_string(reinterpret_cast<uint32_t &>(buf) * sign);
        case 2:
            // result is short...
            return to_string(reinterpret_cast<uint16_t &>(buf) * sign);
    }

    return "";
}

string d_number(ScanState &scanState, int length, bool negative) {
    return dnumber_primitive(scanState, length, negative);
}

unsigned char d_byte(ScanState &scanState) {

    static const string alphabet_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef";

    // if it is nested, decrement depth level and return 0
    // (sorta feels like it should never happen)
    if (scanState.decrement_node_depth()) {
        return 0;
    }

    char cur = scanState.pop();

    // if result is capital letter...
    if (iscapital(cur)) {
        return cur - 'A';
    } else {
        // cur must be within [103, 111]
        int n = (cur - 0x67) * 32; // ranges from 0 to 256
        char second = scanState.pop();
        size_t up_index = alphabet_upper.find(second);

        // seemingly takes advantage of 8-bit overflow...
        return (unsigned char) (n + up_index);
    }
}

string d_variant(ScanState &scanState) {

    string result;

    // types are 'b':null 'c':boolean 'd':number 'e':string
    uint_fast8_t type = scanState.pop() - 'a';

    switch (type) {
        case 1: // 'b'
            // null type
            result = "null";
            break;
        case 2: // 'c'
            // boolean type
            result = d_bool(scanState) ? "true" : "false";
            break;
        case 3: // 'd'
            // number type
            result = d_number(scanState, 0,0);
            break;
        case 4: // 'e'
            // string type
            break;
    }

    return result;
}

