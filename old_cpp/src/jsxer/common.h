#pragma once

#include <vector>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

#define BEGIN_NS(ns) namespace ns {

#define END_NS(ns) }

#define _in_range(min,max,x) \
    (((x) - (min)) * ((max) - (x)) > 0)

#define _in_range_i(min,max,x) \
    (((x) - (min)) * ((max) - (x)) >= 0)

#define in_range(min,max,x) \
    (((x) > (min)) && ((x) < (max)))

#define in_range_i(min,max,x) \
    (((x) >= (min)) && ((x) <= (max)))

#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
    #define CPP_17_PLUS
#endif


typedef uint8_t Token;

typedef uint8_t Byte;
typedef double Number;

using String = std::string;
using Bytes = std::vector<uint8_t>;
using ByteString = std::vector<uint16_t>;