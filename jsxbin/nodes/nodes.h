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
        LogicalExp = 'U',
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
        switch(nodeType){
            case ArgumentList: return new class ArgumentList(scanState);
            case ArrayExpr: return new class ArrayExpr(scanState);
            case ArrayIndexingExpr: return new class ArrayIndexingExpr(scanState);
            case AssignmentExpr: return new class AssignmentExpr(scanState);
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
        }
        return nullptr;
    }

}

#endif //JSXBIN_DECOMPILER_NODES_H
