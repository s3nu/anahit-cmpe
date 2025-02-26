/**
 * <h1>WhenStatementParser</h1>
 *
 * <p>Parse a Pascal CASE statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <set>
#include "WhenStatementParser.h"
#include "StatementParser.h"
#include "AssignmentStatementParser.h"
#include "ExpressionParser.h"
#include "../PascalParserTD.h"
#include "../PascalToken.h"
#include "../PascalError.h"
#include "../../Token.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/ICodeFactory.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;
using namespace wci::intermediate::icodeimpl;

set<PascalTokenType> WhenStatementParser::CONSTANT_START_SET =
{
    PT_IDENTIFIER, PT_INTEGER, PT_PLUS, PT_MINUS, PT_STRING, PT_REAL, PT_LEFT_PAREN
};

set<PascalTokenType> WhenStatementParser::OTHERWISE_SET;
set<PascalTokenType> WhenStatementParser::EQUAL_RIGHT_ARROW_SET;

bool WhenStatementParser::INITIALIZED = false;

void WhenStatementParser::initialize()
{
    if (INITIALIZED) return;

    EQUAL_RIGHT_ARROW_SET.insert(PascalTokenType::EQUAL_RIGHT_ARROW);
    set<PascalTokenType>::iterator it;
    for (it  = StatementParser::STMT_START_SET.begin();
         it != StatementParser::STMT_START_SET.end();
         it++)
    {
        EQUAL_RIGHT_ARROW_SET.insert(*it);
        OTHERWISE_SET.insert(*it);
    }
    for (it  = StatementParser::STMT_FOLLOW_SET.begin();
         it != StatementParser::STMT_FOLLOW_SET.end();
         it++)
    {
        OTHERWISE_SET.insert(*it);
        EQUAL_RIGHT_ARROW_SET.insert(*it);
    }

    INITIALIZED = true;
}

WhenStatementParser::WhenStatementParser(PascalParserTD *parent)
    : StatementParser(parent)
{
    initialize();
}

ICodeNode *WhenStatementParser::parse_statement(Token *token) throw (string)
{
    token = next_token(token);  // consume the WHEN

    // Create a SELECT node.
    ICodeNode *select_node =
            ICodeFactory::create_icode_node((ICodeNodeType) NT_WHEN);


    // Loop to parse each WHEN branch until the END token
    // or the end of the source file.
    while ((token != nullptr) &&
           (token->get_type() != (TokenType) PT_END))
    {
        // The SELECT node adopts the CASE branch subtree.
        select_node->add_child(parse_branch(token));

        token = current_token();
        TokenType token_type = token->get_type();

        // Look for the semicolon between CASE branches.
        if (token_type == (TokenType) PT_SEMICOLON)
        {
            token = next_token(token);  // consume the ;
        }

        // If at the start of the next constant, then missing a semicolon.
        else if (CONSTANT_START_SET.find((PascalTokenType) token_type)
                      != CONSTANT_START_SET.end())
        {
            error_handler.flag(token, MISSING_SEMICOLON, this);
        }
    }

    // Look for the END token.
    if (token->get_type() == (TokenType) PT_END)
    {
        token = next_token(token);  // consume END
    }
    else
    {
        error_handler.flag(token, MISSING_END, this);
    }

    return select_node;
}

ICodeNode *WhenStatementParser::parse_branch(Token *token)
    throw (string)
{
    // Create an SELECT_BRANCH node and a SELECT_EXPRESSION node.
    // The SELECT_BRANCH node adopts the SELECT_EXPRESSION node as its
    // first child.
    ICodeNode *branch_node = nullptr;
    ICodeNode *assignment_node = nullptr;

    if(token->get_type() == (TokenType) PT_OTHERWISE){
        token = next_token(token);  // consume OTHERWISE
    }
    else{
        branch_node =
            ICodeFactory::create_icode_node(
                                       (ICodeNodeType) NT_SELECT_BRANCH);
        ExpressionParser expression_parser(this);
        branch_node->add_child(expression_parser.parse_statement(token));

    }

    // Parse the list of WHEN branch expressions.
    // The SELECT_CONSTANTS node adopts each constant.
    // Look for the "=>" token.
    token = synchronize(EQUAL_RIGHT_ARROW_SET);
    if (token->get_type() == (TokenType) PT_EQUAL_RIGHT_ARROW)
    {
        token = next_token(token);  // consume the "=>"
    }
    else
    {
        error_handler.flag(token, MISSING_EQUAL_RIGHT_ARROW, this);
    }

    // Parse the WHEN branch statement. The SELECT_BRANCH node adopts
    // the statement subtree as its second child.
    StatementParser statementParser(this);
    assignment_node = statementParser.parse_statement(token);
    if(branch_node!=nullptr){
        branch_node->add_child(assignment_node);
    }
    else{
        branch_node = assignment_node;
    }

    return branch_node; //Returns WHEN branch node with a list of child list expressions
}

ICodeNode *WhenStatementParser::parse_expression(Token *token)
    throw (string)
{

    ICodeNode *expression_node = nullptr;
    // Synchronize at the start of a constant.
    token = synchronize(CONSTANT_START_SET);
    // Parse the expressions.
    ExpressionParser expression_parser(this);
    expression_node = expression_parser.parse_statement(token);
    return expression_node;
}

}}}}  // namespace wci::frontend::pascal::parsers
