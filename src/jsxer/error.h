//
// Created by Angelo DeLuca on 9/10/26.
//

#ifndef JSXER_ERROR_H
#define JSXER_ERROR_H
#include <stdexcept>

enum class ParseErrorKind : int {
    None = 0,

    InvalidVersion,
    ReachedEnd,
    DecodeError,
    NoData,
    InvalidNode
};

class JsxerParseError : public std::runtime_error {
public:
    explicit JsxerParseError(std::string msg, ParseErrorKind kind) : std::runtime_error(msg), kind_(kind) {}

    ParseErrorKind kind_;
};

#endif //JSXER_ERROR_H
