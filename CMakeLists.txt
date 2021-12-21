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
        jsxbin/jsxbin.cpp
        jsxbin/jsxbin.h

        jsxbin/nodes/nodes.h
        jsxbin/nodes/ArgumentList.h
        jsxbin/nodes/ArrayExpr.h
        jsxbin/nodes/ArrayIndexingExpr.h
        jsxbin/nodes/AssignmentExpr.h
        jsxbin/nodes/BinaryExpr.cpp
        jsxbin/nodes/BinaryExpr.h
        jsxbin/nodes/ConditionalExpr.cpp
        jsxbin/nodes/ConditionalExpr.h
        jsxbin/nodes/ConstDeclaration.cpp
        jsxbin/nodes/ConstDeclaration.h
        jsxbin/nodes/DebuggerStatement.cpp
        jsxbin/nodes/DebuggerStatement.h
        jsxbin/nodes/DeleteExpr.cpp
        jsxbin/nodes/DeleteExpr.h
        jsxbin/nodes/DoWhileExpr.cpp
        jsxbin/nodes/DoWhileExpr.h
        jsxbin/nodes/ExprNode.cpp
        jsxbin/nodes/ExprNode.h
        jsxbin/nodes/ForInStatement.cpp
        jsxbin/nodes/ForInStatement.h
        jsxbin/nodes/ForStatement.cpp
        jsxbin/nodes/ForStatement.h
        jsxbin/nodes/FunctionCallExpr.cpp
        jsxbin/nodes/FunctionCallExpr.h
        jsxbin/nodes/FunctionDeclaration.cpp jsxbin/nodes/FunctionDeclaration.h jsxbin/nodes/FunctionExpr.cpp jsxbin/nodes/FunctionExpr.h jsxbin/nodes/IdNode.cpp jsxbin/nodes/IdNode.h)
