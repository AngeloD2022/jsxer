cmake_minimum_required(VERSION 3.20)
project(jsxbin_decompiler)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(jsxbin_decomp STATIC
    src/jsxbin/jsxbin.cpp
    src/jsxbin/util.h
    src/jsxbin/util.cpp
    src/jsxbin/decoders.cpp
    src/jsxbin/decoders.h
    src/jsxbin/reader.cpp
    src/jsxbin/reader.h
    src/jsxbin/nodes/AstNode.h
    src/jsxbin/nodes/RootNode.cpp
    src/jsxbin/nodes/RootNode.h
    src/jsxbin/nodes/nodes.h
    src/jsxbin/nodes/ArgumentList.cpp
    src/jsxbin/nodes/ArgumentList.h
    src/jsxbin/nodes/ArrayExpr.cpp
    src/jsxbin/nodes/ArrayExpr.h
    src/jsxbin/nodes/ArrayIndexingExpr.cpp
    src/jsxbin/nodes/ArrayIndexingExpr.h
    src/jsxbin/nodes/AssignmentExpr.cpp
    src/jsxbin/nodes/AssignmentExpr.h
    src/jsxbin/nodes/BinaryExpr.cpp
    src/jsxbin/nodes/BinaryExpr.h
    src/jsxbin/nodes/ConditionalExpr.cpp
    src/jsxbin/nodes/ConditionalExpr.h
    src/jsxbin/nodes/ConstDeclaration.cpp
    src/jsxbin/nodes/ConstDeclaration.h
    src/jsxbin/nodes/DebuggerStatement.cpp
    src/jsxbin/nodes/DebuggerStatement.h
    src/jsxbin/nodes/DeleteExpr.cpp
    src/jsxbin/nodes/DeleteExpr.h
    src/jsxbin/nodes/DoWhileExpr.cpp
    src/jsxbin/nodes/DoWhileExpr.h
    src/jsxbin/nodes/ExprNode.cpp
    src/jsxbin/nodes/ExprNode.h
    src/jsxbin/nodes/ForInStatement.cpp
    src/jsxbin/nodes/ForInStatement.h
    src/jsxbin/nodes/ForStatement.cpp
    src/jsxbin/nodes/ForStatement.h
    src/jsxbin/nodes/ForStatement2.cpp
    src/jsxbin/nodes/ForStatement2.h
    src/jsxbin/nodes/FunctionCallExpr.cpp
    src/jsxbin/nodes/FunctionCallExpr.h
    src/jsxbin/nodes/FunctionDeclaration.cpp
    src/jsxbin/nodes/FunctionDeclaration.h
    src/jsxbin/nodes/FunctionExpr.cpp
    src/jsxbin/nodes/FunctionExpr.h
    src/jsxbin/nodes/IdNode.cpp
    src/jsxbin/nodes/IdNode.h
    src/jsxbin/nodes/IdRefExpr.cpp
    src/jsxbin/nodes/IdRefExpr.h
    src/jsxbin/nodes/IfStatement.cpp
    src/jsxbin/nodes/IfStatement.h
    src/jsxbin/nodes/IncrementExpr.cpp
    src/jsxbin/nodes/IncrementExpr.h
    src/jsxbin/nodes/IndexingIncrementExpr.cpp
    src/jsxbin/nodes/IndexingIncrementExpr.h
    src/jsxbin/nodes/JumpStatement.cpp
    src/jsxbin/nodes/JumpStatement.h
    src/jsxbin/nodes/LogicalExpr.cpp
    src/jsxbin/nodes/LogicalExpr.h
    src/jsxbin/nodes/MemberAssignmentExpr.cpp
    src/jsxbin/nodes/MemberAssignmentExpr.h
    src/jsxbin/nodes/MemberExpr.cpp
    src/jsxbin/nodes/MemberExpr.h
    src/jsxbin/nodes/ObjectExpr.cpp
    src/jsxbin/nodes/ObjectExpr.h
    src/jsxbin/nodes/RegExpLiteral.cpp
    src/jsxbin/nodes/RegExpLiteral.h
    src/jsxbin/nodes/ReturnStatement.cpp
    src/jsxbin/nodes/ReturnStatement.h
    src/jsxbin/nodes/SetDefaultXMLNamespaceExpr.cpp
    src/jsxbin/nodes/SetDefaultXMLNamespaceExpr.h
    src/jsxbin/nodes/StatementList.cpp
    src/jsxbin/nodes/StatementList.h
    src/jsxbin/nodes/SwitchStatement.cpp
    src/jsxbin/nodes/SwitchStatement.h
    src/jsxbin/nodes/ThisExpr.cpp
    src/jsxbin/nodes/ThisExpr.h
    src/jsxbin/nodes/ThrowStatement.cpp
    src/jsxbin/nodes/ThrowStatement.h
    src/jsxbin/nodes/TryStatement.cpp
    src/jsxbin/nodes/TryStatement.h
    src/jsxbin/nodes/UnaryExpr.cpp
    src/jsxbin/nodes/UnaryExpr.h
    src/jsxbin/nodes/UnknownNode.cpp
    src/jsxbin/nodes/UnknownNode.h
    src/jsxbin/nodes/ValueNode.cpp
    src/jsxbin/nodes/ValueNode.h
    src/jsxbin/nodes/WhileStatement.cpp
    src/jsxbin/nodes/WhileStatement.h
    src/jsxbin/nodes/WithStatement.cpp
    src/jsxbin/nodes/WithStatement.h
    src/jsxbin/nodes/XMLAccessorExpr.cpp
    src/jsxbin/nodes/XMLAccessorExpr.h
    src/jsxbin/nodes/XMLAssignmentExpr.cpp
    src/jsxbin/nodes/XMLAssignmentExpr.h
    src/jsxbin/nodes/XMLDoubleDotDescendantsExpr.cpp
    src/jsxbin/nodes/XMLDoubleDotDescendantsExpr.h
    src/jsxbin/nodes/XMLNamespaceExpr.cpp
    src/jsxbin/nodes/XMLNamespaceExpr.h
)

add_executable(jsxbin_decompiler src/cli/main.cpp)
target_include_directories(jsxbin_decompiler PUBLIC src/jsxbin)
target_link_libraries(jsxbin_decompiler jsxbin_decomp)

add_library(libjd SHARED src/dll/library.cpp src/dll/library.h)
target_include_directories(libjd PUBLIC src/jsxbin)
target_link_libraries(libjd jsxbin_decomp)
