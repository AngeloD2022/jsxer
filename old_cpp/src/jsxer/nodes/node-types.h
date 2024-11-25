#pragma once

#include <cstdint>

#include "../common.h"

namespace jsxer::nodes {
    enum class NodeType : uint8_t {
        Invalid = (uint8_t) -1,

        Program = '\x00',

        ArrayExpression = 'A',
        AssignmentExpression = 'B',
        BinaryExpression = 'C',
        BreakStatement = 'D',
        CallExpression = 'E',
        ConstantLiteral = 'F',
        ConstAssignment = 'G',
        DebuggerStatement = 'H',
        DoWhileStatement = 'I',
        ExpressionStatement = 'J',
        ForStatement = 'K',
        ForInStatement = 'L',
        FunctionDeclaration = 'M',
        FunctionExpression = 'N',
        IfStatement = 'O',
        UpdateExpression = 'P',
        IndexingExpression = 'Q',
        ListExpression = 'R',
        LocalAssignmentExpression = 'S',
        LocalUpdateExpression = 'T',
        LogicalExpression = 'U',
        LocalIdentifier = 'V',
        ObjectExpression = 'W',
        MemberExpression = 'X',
        RegExpLiteral = 'Y',
        ReturnStatement = 'Z',

        SimpleForStatement = 'a',
        StatementList = 'b',
        SwitchStatement = 'c',
        TernaryExpression = 'd',
        ThisExpression = 'e',
        ThrowStatement = 'f',
        TryStatement = 'g',
        UnaryExpression = 'h',
        UnaryRefExpression = 'i',
        Identifier = 'j',
        VoidExpression = 'k',
        WhileStatement = 'l',
        WithStatement = 'm',

        EmptyExpression = 'n',

        XMLConstantExpression = 'o',
        XMLQualifiedNameExpression = 'p',
        XMLDescendantsExpression = 'q',
        XMLPredicateExpression = 'r',
        XMLUnaryRefExpression = 's',
    };
}
