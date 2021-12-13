//
// Created by Angelo DeLuca on 12/1/21.
//

#ifndef JSXBIN_DECOMPILER_NODES_H
#define JSXBIN_DECOMPILER_NODES_H

#include "AbstractNode.h"
#include "ArgumentList.h"
#include "ArrayExpr.h"
#include "ArrayIndexingExpr.h"

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
            case ArgumentList: return new ArgumentList(scanState);
            case ArrayExpr: return new ArrayExpr(scanState);
            case ArrayIndexingExpr: return new ArrayIndexingExpr(scanState);
        }
    }

}

#endif //JSXBIN_DECOMPILER_NODES_H
