#include "ArgumentList.h"

void ArgumentList::parse() {
    arguments = decoders::d_children(scanState);
    unkValue = decoders::d_bool(scanState);
}

string ArgumentList::jsx() {
    string result;
    for (int i = 0; i < arguments.size(); ++i) {
        result += arguments[i]->jsx() + (i + 1 == arguments.size() ? "" : ", ");
    }

    return result;
}