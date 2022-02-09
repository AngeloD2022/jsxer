cmake_minimum_required(VERSION 3.20)
project(jsxbin_decompiler)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(jsxbin_decomp STATIC
    src/jsxbin/jsxbin.cpp
    src/jsxbin/common.h
    src/jsxbin/util.h
    src/jsxbin/util.cpp
    src/jsxbin/decoders.cpp
    src/jsxbin/decoders.h
    src/jsxbin/reader.cpp
    src/jsxbin/reader.h
    src/jsxbin/nodes/nodes.h
    src/jsxbin/nodes/node-types.h
    src/jsxbin/nodes/AstNode.h
    src/jsxbin/nodes/Program.cpp
    src/jsxbin/nodes/Program.h
    src/jsxbin/nodes/ListExpression.cpp
    src/jsxbin/nodes/ListExpression.h
    src/jsxbin/nodes/ArrayExpression.cpp
    src/jsxbin/nodes/ArrayExpression.h
    src/jsxbin/nodes/IndexingExpression.cpp
    src/jsxbin/nodes/IndexingExpression.h
    src/jsxbin/nodes/LocalAssignmentExpression.cpp
    src/jsxbin/nodes/LocalAssignmentExpression.h
    src/jsxbin/nodes/BinaryExpression.cpp
    src/jsxbin/nodes/BinaryExpression.h
    src/jsxbin/nodes/TernaryExpression.cpp
    src/jsxbin/nodes/TernaryExpression.h
    src/jsxbin/nodes/ConstAssignment.cpp
    src/jsxbin/nodes/ConstAssignment.h
    src/jsxbin/nodes/DebuggerStatement.cpp
    src/jsxbin/nodes/DebuggerStatement.h
    src/jsxbin/nodes/UnaryRefExpression.cpp
    src/jsxbin/nodes/UnaryRefExpression.h
    src/jsxbin/nodes/DoWhileStatement.cpp
    src/jsxbin/nodes/DoWhileStatement.h
    src/jsxbin/nodes/ExpressionStatement.cpp
    src/jsxbin/nodes/ExpressionStatement.h
    src/jsxbin/nodes/ForInStatement.cpp
    src/jsxbin/nodes/ForInStatement.h
    src/jsxbin/nodes/SimpleForStatement.cpp
    src/jsxbin/nodes/SimpleForStatement.h
    src/jsxbin/nodes/ForStatement.cpp
    src/jsxbin/nodes/ForStatement.h
    src/jsxbin/nodes/CallExpression.cpp
    src/jsxbin/nodes/CallExpression.h
    src/jsxbin/nodes/FunctionDeclaration.cpp
    src/jsxbin/nodes/FunctionDeclaration.h
    src/jsxbin/nodes/FunctionExpression.cpp
    src/jsxbin/nodes/FunctionExpression.h
    src/jsxbin/nodes/Identifier.cpp
    src/jsxbin/nodes/Identifier.h
    src/jsxbin/nodes/LocalIdentifier.cpp
    src/jsxbin/nodes/LocalIdentifier.h
    src/jsxbin/nodes/IfStatement.cpp
    src/jsxbin/nodes/IfStatement.h
    src/jsxbin/nodes/LocalUpdateExpression.cpp
    src/jsxbin/nodes/LocalUpdateExpression.h
    src/jsxbin/nodes/UpdateExpression.cpp
    src/jsxbin/nodes/UpdateExpression.h
    src/jsxbin/nodes/BreakStatement.cpp
    src/jsxbin/nodes/BreakStatement.h
    src/jsxbin/nodes/LogicalExpression.cpp
    src/jsxbin/nodes/LogicalExpression.h
    src/jsxbin/nodes/AssignmentExpression.cpp
    src/jsxbin/nodes/AssignmentExpression.h
    src/jsxbin/nodes/MemberExpression.cpp
    src/jsxbin/nodes/MemberExpression.h
    src/jsxbin/nodes/ObjectExpression.cpp
    src/jsxbin/nodes/ObjectExpression.h
    src/jsxbin/nodes/RegExpLiteral.cpp
    src/jsxbin/nodes/RegExpLiteral.h
    src/jsxbin/nodes/ReturnStatement.cpp
    src/jsxbin/nodes/ReturnStatement.h
    src/jsxbin/nodes/EmptyExpression.cpp
    src/jsxbin/nodes/EmptyExpression.h
    src/jsxbin/nodes/VoidExpression.cpp
    src/jsxbin/nodes/VoidExpression.h
    src/jsxbin/nodes/StatementList.cpp
    src/jsxbin/nodes/StatementList.h
    src/jsxbin/nodes/SwitchStatement.cpp
    src/jsxbin/nodes/SwitchStatement.h
    src/jsxbin/nodes/ThisExpression.cpp
    src/jsxbin/nodes/ThisExpression.h
    src/jsxbin/nodes/ThrowStatement.cpp
    src/jsxbin/nodes/ThrowStatement.h
    src/jsxbin/nodes/TryStatement.cpp
    src/jsxbin/nodes/TryStatement.h
    src/jsxbin/nodes/UnaryExpression.cpp
    src/jsxbin/nodes/UnaryExpression.h
    src/jsxbin/nodes/XMLUnaryRefExpression.cpp
    src/jsxbin/nodes/XMLUnaryRefExpression.h
    src/jsxbin/nodes/ConstantLiteral.cpp
    src/jsxbin/nodes/ConstantLiteral.h
    src/jsxbin/nodes/WhileStatement.cpp
    src/jsxbin/nodes/WhileStatement.h
    src/jsxbin/nodes/WithStatement.cpp
    src/jsxbin/nodes/WithStatement.h
    src/jsxbin/nodes/XMLPredicateExpression.cpp
    src/jsxbin/nodes/XMLPredicateExpression.h
    src/jsxbin/nodes/XMLConstantExpression.cpp
    src/jsxbin/nodes/XMLConstantExpression.h
    src/jsxbin/nodes/XMLQualifiedNameExpression.cpp
    src/jsxbin/nodes/XMLQualifiedNameExpression.h
    src/jsxbin/nodes/XMLDescendantsExpression.cpp
    src/jsxbin/nodes/XMLDescendantsExpression.h
)

add_executable(jsxbin_decompiler src/cli/main.cpp)
target_include_directories(jsxbin_decompiler PUBLIC src/jsxbin)
target_link_libraries(jsxbin_decompiler jsxbin_decomp)

add_library(libjd SHARED src/dll/library.cpp src/dll/library.h)
target_include_directories(libjd PUBLIC src/jsxbin)
target_link_libraries(libjd jsxbin_decomp)
