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

namespace jsxer::nodes {
    AstOpNode get(NodeType type, Reader &reader) {
        switch (type) {
            case NodeType::ArrayExpression:
                return std::make_shared<ArrayExpression>(reader);
            case NodeType::AssignmentExpression:
                return std::make_shared<AssignmentExpression>(reader);
            case NodeType::BinaryExpression:
                return std::make_shared<BinaryExpression>(reader);
            case NodeType::BreakStatement:
                return std::make_shared<BreakStatement>(reader);
            case NodeType::CallExpression:
                return std::make_shared<CallExpression>(reader);
            case NodeType::ConstantLiteral:
                return std::make_shared<ConstantLiteral>(reader);
            case NodeType::ConstAssignment:
                return std::make_shared<ConstAssignment>(reader);
            case NodeType::DebuggerStatement:
                return std::make_shared<DebuggerStatement>(reader);
            case NodeType::DoWhileStatement:
                return std::make_shared<DoWhileStatement>(reader);
            case NodeType::ExpressionStatement:
                return std::make_shared<ExpressionStatement>(reader);
            case NodeType::ForStatement:
                return std::make_shared<ForStatement>(reader);
            case NodeType::ForInStatement:
                return std::make_shared<ForInStatement>(reader);
            case NodeType::FunctionDeclaration:
                return std::make_shared<FunctionDeclaration>(reader);
            case NodeType::FunctionExpression:
                return std::make_shared<FunctionExpression>(reader);
            case NodeType::IfStatement:
                return std::make_shared<IfStatement>(reader);
            case NodeType::UpdateExpression:
                return std::make_shared<UpdateExpression>(reader);
            case NodeType::IndexingExpression:
                return std::make_shared<IndexingExpression>(reader);
            case NodeType::ListExpression:
                return std::make_shared<ListExpression>(reader);
            case NodeType::LocalAssignmentExpression:
                return std::make_shared<LocalAssignmentExpression>(reader);
            case NodeType::LocalUpdateExpression:
                return std::make_shared<LocalUpdateExpression>(reader);
            case NodeType::LogicalExpression:
                return std::make_shared<LogicalExpression>(reader);
            case NodeType::LocalIdentifier:
                return std::make_shared<LocalIdentifier>(reader);
            case NodeType::ObjectExpression:
                return std::make_shared<ObjectExpression>(reader);
            case NodeType::MemberExpression:
                return std::make_shared<MemberExpression>(reader);
            case NodeType::RegExpLiteral:
                return std::make_shared<RegExpLiteral>(reader);
            case NodeType::ReturnStatement:
                return std::make_shared<ReturnStatement>(reader);

            case NodeType::SimpleForStatement:
                return std::make_shared<SimpleForStatement>(reader);
            case NodeType::StatementList:
                return std::make_shared<StatementList>(reader);
            case NodeType::SwitchStatement:
                return std::make_shared<SwitchStatement>(reader);
            case NodeType::TernaryExpression:
                return std::make_shared<TernaryExpression>(reader);
            case NodeType::ThisExpression:
                return std::make_shared<ThisExpression>(reader);
            case NodeType::ThrowStatement:
                return std::make_shared<ThrowStatement>(reader);
            case NodeType::TryStatement:
                return std::make_shared<TryStatement>(reader);
            case NodeType::UnaryExpression:
                return std::make_shared<UnaryExpression>(reader);
            case NodeType::UnaryRefExpression:
                return std::make_shared<UnaryRefExpression>(reader);
            case NodeType::Identifier:
                return std::make_shared<Identifier>(reader);
            case NodeType::VoidExpression:
                return std::make_shared<VoidExpression>(reader);
            case NodeType::WhileStatement:
                return std::make_shared<WhileStatement>(reader);
            case NodeType::WithStatement:
                return std::make_shared<WithStatement>(reader);

            // Note: need to do some empty expr tests before uncommenting this
            // case NodeType::EmptyExpression:
            //    return std::make_shared<EmptyExpression>(reader);

            case NodeType::XMLConstantExpression:
                return std::make_shared<XMLConstantExpression>(reader);
            case NodeType::XMLQualifiedNameExpression:
                return std::make_shared<XMLQualifiedNameExpression>(reader);
            case NodeType::XMLDescendantsExpression:
                return std::make_shared<XMLDescendantsExpression>(reader);
            case NodeType::XMLPredicateExpression:
                return std::make_shared<XMLPredicateExpression>(reader);
            case NodeType::XMLUnaryRefExpression:
                return std::make_shared<XMLUnaryRefExpression>(reader);
            default:
                return nullptr;
        }
    }
}
