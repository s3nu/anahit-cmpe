/**
 * <h1>CaseStatementParser</h1>
 *
 * <p>Parse a Pascal CASE statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WHENSTATEMENTPARSER_H_
#define WHENSTATEMENTPARSER_H_

#include <string>
#include <set>
#include "StatementParser.h"
#include "../../Token.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;

class WhenStatementParser : public StatementParser
{
public:
    /**
     * Constructor.
     * @param parent the parent parser.
     */
    WhenStatementParser(PascalParserTD *parent);

    /**
     * Parse an IF statement.
     * @param token the initial token.
     * @return the root node of the generated parse tree.
     * @throw a string message if an error occurred.
     */
    ICodeNode *parse_statement(Token *token) throw (string);

private:
    // Synchronization set for starting a WHEN option constant.
    static set<PascalTokenType> EQUAL_RIGHT_ARROW_SET;

    // Synchronization set for OTHERWISE.
    static set<PascalTokenType> OTHERWISE_SET;

    static set<PascalTokenType> CONSTANT_START_SET;



    static bool INITIALIZED;

    /**
     * Initialize the synchronization sets.
     */
    static void initialize();

    /**
     * Parse a WHEN branch.
     * @param token the current token.
     * @return the root SELECT_BRANCH node of the subtree.
     * @throw a string message if an error occurred.
     */
    ICodeNode *parse_branch(Token *token)
        throw (string);

    /**
     * Parse a character WHEN constant.
     * @param token the current token.
     * @param value the token value string.
     * @param sign the sign, if any.
     * @return the constant node.
     */
    ICodeNode *parse_character_constant(Token *token, const string value,
                                        const bool minus_sign);

    /**
     * Parse a expression.
     * @param token the current token.
     * @return the root expression node of the subtree.
     * @throw a string message if an error occurred.
     */
    ICodeNode *parse_expression(Token *token)
        throw (string);
};

}}}}  // namespace wci::frontend::pascal::parsers

#endif /* WHENTATEMENTPARSER_H_ */
