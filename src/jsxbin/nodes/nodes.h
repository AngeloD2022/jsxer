#pragma once

#include "AstNode.h"

#include "ArgumentList.h"
#include "ArrayExpr.h"
#include "ArrayIndexingExpr.h"
#include "AssignmentExpr.h"
#include "BinaryExpr.h"
#include "ConditionalExpr.h"
#include "ConstDeclaration.h"
#include "DebuggerStatement.h"
#include "DeleteExpr.h"
#include "DoWhileExpr.h"
#include "ExprNode.h"
#include "ForInStatement.h"
#include "ForStatement.h"
#include "ForStatement2.h"
#include "FunctionCallExpr.h"
#include "FunctionDeclaration.h"
#include "FunctionExpr.h"
#include "IdNode.h"
#include "IdRefExpr.h"
#include "IfStatement.h"
#include "IncrementExpr.h"
#include "IndexingIncrementExpr.h"
#include "JumpStatement.h"
#include "LogicalExpr.h"
#include "MemberAssignmentExpr.h"
#include "MemberExpr.h"
#include "ObjectExpr.h"
#include "RegExpLiteral.h"
#include "ReturnStatement.h"
#include "SetDefaultXMLNamespaceExpr.h"
#include "StatementList.h"
#include "SwitchStatement.h"
#include "ThisExpr.h"
#include "ThrowStatement.h"
#include "TryStatement.h"
#include "UnaryExpr.h"
#include "UnknownNode.h"
#include "ValueNode.h"
#include "WhileStatement.h"
#include "WithStatement.h"
#include "XMLAccessorExpr.h"
#include "XMLAssignmentExpr.h"
#include "XMLDoubleDotDescendantsExpr.h"
#include "XMLNamespaceExpr.h"

namespace jsxbin { namespace nodes {
    enum NodeType {
        ArgumentList = 'R',
        ArrayExpr = 'A',
        ArrayIndexingExpr = 'Q',
        AssignmentExpr = 'S',
        BinaryExpr = 'C',
        ConditionalExpr = 'd',
        ConstDeclaration = 'G',
        DebuggerStatement = 'H',
        DeleteExpr = 'i',
        DoWhileExpr = 'I',
        ExprNode = 'J',
        ForInStatement = 'L',
        ForStatement = 'a',
        ForStatement2 = 'K',
        FunctionCallExpr = 'E',
        FunctionDeclaration = 'M',
        FunctionExpr = 'N',
        IdNode = 'j',
        IdRefExpr = 'V',
        IfStatement = 'O',
        IncrementExpr = 'T',
        IndexingIncrementExpr = 'P',
        JumpStatement = 'D',
        LogicalExpr = 'U',
        MemberAssignmentExpr = 'B',
        MemberExpr = 'X',
        ObjectExpr = 'W',
        RegExpLiteral = 'Y',
        ReturnStatement = 'Z',
        SetDefaultXMLNamespaceExpr = 'k',
        StatementList = 'b',
        SwitchStatement = 'c',
        ThisExpr = 'e',
        ThrowStatement = 'f',
        TryStatement = 'g',
        UnaryExpr = 'h',
        UnknownNode = 's',
        ValueNode = 'F',
        WhileStatement = 'l',
        WithStatement = 'm',
        XMLAccessorExpr = 'r',
        XMLAssignmentExpr = 'o',
        XMLDoubleDotDescendantsExpr = 'q',
        XMLNamespaceExpr = 'p'
    };

    AstNode* get(NodeType type, Reader& reader) {
        switch (type) {
            case ArgumentList: return new class ArgumentList(reader);
            case ArrayExpr: return new class ArrayExpr(reader);
            case ArrayIndexingExpr: return new class ArrayIndexingExpr(reader);
            case AssignmentExpr: return new class AssignmentExpr(reader);
            case BinaryExpr: return new class BinaryExpr(reader);
            case ConditionalExpr: return new class ConditionalExpr(reader);
            case ConstDeclaration: return new class ConstDeclaration(reader);
            case DebuggerStatement: return new class DebuggerStatement(reader);
            case DeleteExpr: return new class DeleteExpr(reader);
            case DoWhileExpr: return new class DoWhileExpr(reader);
            case ExprNode: return new class ExprNode(reader);
            case ForInStatement: return new class ForInStatement(reader);
            case ForStatement: return new class ForStatement(reader);
            case ForStatement2: return new class ForStatement2(reader);
            case FunctionCallExpr: return new class FunctionCallExpr(reader);
            case FunctionDeclaration: return new class FunctionDeclaration(reader);
            case FunctionExpr: return new class FunctionExpr(reader);
            case IdNode: return new class IdNode(reader);
            case IdRefExpr: return new class IdRefExpr(reader);
            case IfStatement: return new class IfStatement(reader);
            case IncrementExpr: return new class IncrementExpr(reader);
            case IndexingIncrementExpr: return new class IndexingIncrementExpr(reader);
            case JumpStatement: return new class JumpStatement(reader);
            case LogicalExpr: return new class LogicalExpr(reader);
            case MemberAssignmentExpr: return new class MemberAssignmentExpr(reader);
            case MemberExpr: return new class MemberExpr(reader);
            case ObjectExpr: return new class ObjectExpr(reader);
            case RegExpLiteral: return new class RegExpLiteral(reader);
            case ReturnStatement: return new class ReturnStatement(reader);
            case SetDefaultXMLNamespaceExpr: return new class SetDefaultXMLNamespaceExpr(reader);
            case StatementList: return new class StatementList(reader);
            case SwitchStatement: return new class SwitchStatement(reader);
            case ThisExpr: return new class ThisExpr(reader);
            case ThrowStatement: return new class ThrowStatement(reader);
            case TryStatement: return new class TryStatement(reader);
            case UnaryExpr: return new class UnaryExpr(reader);
            case UnknownNode: return new class UnknownNode(reader);
            case ValueNode: return new class ValueNode(reader);
            case WhileStatement: return new class WhileStatement(reader);
            case WithStatement: return new class WithStatement(reader);
            case XMLAccessorExpr: return new class XMLAccessorExpr(reader);
            case XMLAssignmentExpr: return new class XMLAssignmentExpr(reader);
            case XMLDoubleDotDescendantsExpr: return new class XMLDoubleDotDescendantsExpr(reader);
            case XMLNamespaceExpr: return new class XMLNamespaceExpr(reader);

            default:
                return nullptr;
        }
    }
} }
