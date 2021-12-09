cmake_minimum_required(VERSION 3.20)
project(jsxbin_decompiler)

set(CMAKE_CXX_STANDARD 20)

add_executable(jsxbin_decompiler
        main.cpp
        jsxbin/decoders.cpp
        jsxbin/decoders.h
        jsxbin/nodes/AbstractNode.h
        jsxbin/ScanState.cpp
        jsxbin/ScanState.h
        jsxbin/nodes/RootNode.h
        jsxbin/jsxbin.cpp jsxbin/jsxbin.h jsxbin/nodes/nodes.h jsxbin/nodes/ArgumentList.h jsxbin/nodes/ArrayExpr.h jsxbin/nodes/ArrayIndexingExpr.h jsxbin/nodes/AssignmentExpr.h jsxbin/nodes/BinaryExpr.cpp jsxbin/nodes/BinaryExpr.h)
