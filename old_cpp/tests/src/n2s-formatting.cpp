#include "./common.h"

const char source[] = R"(
var k = [
    0,
    123,
    -456,
    7.89,
    -0.123,
    1.23e6,
    -4.56e-7,

    1.7976931348623157e+308,
    -1.7976931348623157e+308,
];
)";

const char compiled[] = R"(
@JSXBIN@ES@2.0@MyBbyBn0ABJGnASzBjLByBARJFdAFdjbFdy2mIBFd8kPmCnVhIickPgfiAFd8lQjS
jIkRnNjclflfFd4lQmESAFd8hZhOkFhVFkakeleFd8nfnfnfnfnfnfnPjfFd8nfnfnfnfnfnfnPnffn
ftABB40BiAABAzACByB
)";

int main() {
    string decompiled;

    int err = jsxer::test::decompile(compiled, decompiled, source);

    return err;
}