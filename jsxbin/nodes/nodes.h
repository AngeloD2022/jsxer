//
// Created by Angelo DeLuca on 12/1/21.
//

#ifndef JSXBIN_DECOMPILER_NODES_H
#define JSXBIN_DECOMPILER_NODES_H

#include "AbstractNode.h"
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

namespace jsxbin::nodes {

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
        UnknownNode2 = 's',
        ValueNode = 'F',
        WhileStatement = 'l',
        WithStatement = 'm',
        XMLAccessorExpr = 'r',
        XMLAssignmentExpr = 'o',
        XMLDoubleDotDescendantsExpr = 'q',
        XMLNamespaceExpr = 'p'
    };

    AbstractNode* get_inst(NodeType nodeType, ScanState &scanState){
        // should be able to cast char to node type, making this easier to use!

        switch (nodeType) {
            case ArgumentList: return new class ArgumentList(scanState);
            case ArrayExpr: return new class ArrayExpr(scanState);
            case ArrayIndexingExpr: return new class ArrayIndexingExpr(scanState);
            case AssignmentExpr: return new class AssignmentExpr(scanState);
            case BinaryExpr: return new class BinaryExpr(scanState);
            case ConditionalExpr: return new class ConditionalExpr(scanState);
            case ConstDeclaration: return new class ConstDeclaration(scanState);
            case DebuggerStatement: return new class DebuggerStatement(scanState);
            case DeleteExpr: return new class DeleteExpr(scanState);
            case DoWhileExpr: return new class DoWhileExpr(scanState);
            case ExprNode: return new class ExprNode(scanState);
            case ForInStatement: return new class ForInStatement(scanState);
            case ForStatement: return new class ForStatement(scanState);
            case ForStatement2: return new class ForStatement2(scanState);
            case FunctionCallExpr: return new class FunctionCallExpr(scanState);
            case FunctionDeclaration: return new class FunctionDeclaration(scanState);
            case FunctionExpr: return new class FunctionExpr(scanState);
            case IdNode: return new class IdNode(scanState);
            case IdRefExpr: return new class IdRefExpr(scanState);
            case IfStatement: return new class IfStatement(scanState);
            case IncrementExpr: return new class IncrementExpr(scanState);
            case IndexingIncrementExpr: return new class IndexingIncrementExpr(scanState);
            case JumpStatement: return new class JumpStatement(scanState);
            case LogicalExpr: return new class LogicalExpr(scanState);
            case MemberAssignmentExpr: return new class MemberAssignmentExpr(scanState);
            case MemberExpr: return new class MemberExpr(scanState);
            case ObjectExpr: return new class ObjectExpr(scanState);
            case RegExpLiteral: return new class RegExpLiteral(scanState);
        }
        return nullptr;
    }

}

#endif //JSXBIN_DECOMPILER_NODES_H
