#pragma once

#include "AstNode.h"

#include "ListExpression.h"
#include "ArrayExpression.h"
#include "IndexingExpression.h"
#include "LocalAssignmentExpression.h"
#include "BinaryExpression.h"
#include "TernaryExpression.h"
#include "ConstAssignment.h"
#include "DebuggerStatement.h"
#include "UnaryRefExpression.h"
#include "DoWhileStatement.h"
#include "ExpressionStatement.h"
#include "ForInStatement.h"
#include "SimpleForStatement.h"
#include "ForStatement.h"
#include "CallExpression.h"
#include "FunctionDeclaration.h"
#include "FunctionExpression.h"
#include "Identifier.h"
#include "LocalIdentifier.h"
#include "IfStatement.h"
#include "LocalUpdateExpression.h"
#include "UpdateExpression.h"
#include "BreakStatement.h"
#include "LogicalExpression.h"
#include "AssignmentExpression.h"
#include "MemberExpression.h"
#include "ObjectExpression.h"
#include "RegExpLiteral.h"
#include "ReturnStatement.h"
#include "VoidExpression.h"
#include "StatementList.h"
#include "SwitchStatement.h"
#include "ThisExpression.h"
#include "ThrowStatement.h"
#include "TryStatement.h"
#include "UnaryExpression.h"
#include "XMLUnaryRefExpression.h"
#include "ConstantLiteral.h"
#include "WhileStatement.h"
#include "WithStatement.h"
#include "XMLPredicateExpression.h"
#include "XMLConstantExpression.h"
#include "XMLDescendantsExpression.h"
#include "XMLQualifiedNameExpression.h"

BEGIN_NS(jsxbin) BEGIN_NS(nodes)

AstNode* get(NodeType type, Reader& reader) {
    switch (type) {
        case NodeType::ArrayExpression: return new ArrayExpression(reader);
        case NodeType::AssignmentExpression: return new AssignmentExpression(reader);
        case NodeType::BinaryExpression: return new BinaryExpression(reader);
        case NodeType::BreakStatement: return new BreakStatement(reader);
        case NodeType::CallExpression: return new CallExpression(reader);
        case NodeType::ConstantLiteral: return new ConstantLiteral(reader);
        case NodeType::ConstAssignment: return new ConstAssignment(reader);
        case NodeType::DebuggerStatement: return new DebuggerStatement(reader);
        case NodeType::DoWhileStatement: return new DoWhileStatement(reader);
        case NodeType::ExpressionStatement: return new ExpressionStatement(reader);
        case NodeType::ForStatement: return new ForStatement(reader);
        case NodeType::ForInStatement: return new ForInStatement(reader);
        case NodeType::FunctionDeclaration: return new FunctionDeclaration(reader);
        case NodeType::FunctionExpression: return new FunctionExpression(reader);
        case NodeType::IfStatement: return new IfStatement(reader);
        case NodeType::UpdateExpression: return new UpdateExpression(reader);
        case NodeType::IndexingExpression: return new IndexingExpression(reader);
        case NodeType::ListExpression: return new ListExpression(reader);
        case NodeType::LocalAssignmentExpression: return new LocalAssignmentExpression(reader);
        case NodeType::LocalUpdateExpression: return new LocalUpdateExpression(reader);
        case NodeType::LogicalExpression: return new LogicalExpression(reader);
        case NodeType::LocalIdentifier: return new LocalIdentifier(reader);
        case NodeType::ObjectExpression: return new ObjectExpression(reader);
        case NodeType::MemberExpression: return new MemberExpression(reader);
        case NodeType::RegExpLiteral: return new RegExpLiteral(reader);
        case NodeType::ReturnStatement: return new ReturnStatement(reader);

        case NodeType::SimpleForStatement: return new SimpleForStatement(reader);
        case NodeType::StatementList: return new StatementList(reader);
        case NodeType::SwitchStatement: return new SwitchStatement(reader);
        case NodeType::TernaryExpression: return new TernaryExpression(reader);
        case NodeType::ThisExpression: return new ThisExpression(reader);
        case NodeType::ThrowStatement: return new ThrowStatement(reader);
        case NodeType::TryStatement: return new TryStatement(reader);
        case NodeType::UnaryExpression: return new UnaryExpression(reader);
        case NodeType::UnaryRefExpression: return new UnaryRefExpression(reader);
        case NodeType::Identifier: return new Identifier(reader);
        case NodeType::VoidExpression: return new VoidExpression(reader);
        case NodeType::WhileStatement: return new WhileStatement(reader);
        case NodeType::WithStatement: return new WithStatement(reader);

        // Note: need to do some empty expr tests before uncommenting this
        // case NodeType::EmptyExpression: return new EmptyExpression(reader);

        case NodeType::XMLConstantExpression: return new XMLConstantExpression(reader);
        case NodeType::XMLQualifiedNameExpression: return new XMLQualifiedNameExpression(reader);
        case NodeType::XMLDescendantsExpression: return new XMLDescendantsExpression(reader);
        case NodeType::XMLPredicateExpression: return new XMLPredicateExpression(reader);
        case NodeType::XMLUnaryRefExpression: return new XMLUnaryRefExpression(reader);

        default:
            return nullptr;
    }
}

END_NS(nodes) END_NS(jsxbin)
