/**
 * <h1>JavaParserTD</h1>
 *
 * <p>The top-down Java parser.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <chrono>
#include "JavaParserTD.h"

#include "../Scanner.h"
#include "../Source.h"
#include "../Token.h"
#include "JavaToken.h"
#include "JavaError.h"
#include "../../message/Message.h"

namespace wci { namespace frontend { namespace java {

using namespace std;
using namespace std::chrono;
using namespace wci::frontend;
using namespace wci::message;

JavaErrorHandler JavaParserTD::error_handler;

JavaParserTD::JavaParserTD(Scanner *scanner) : Parser(scanner)
{
    JavaError::initialize();
}

JavaParserTD::JavaParserTD(JavaParserTD *parent)
    : Parser(parent->get_scanner())
{
}

void JavaParserTD::parse() throw (string)
{
    Token *token = nullptr;
    int last_line_number;
    steady_clock::time_point start_time = steady_clock::now();

    // Loop over each token until the end of file.
    while ((token = next_token(token)) != nullptr)
    {
                           //     printf("parse ");
        TokenType token_type = token->get_type();
        last_line_number = token->get_line_number();

        Object value = token->get_value();
        string type_str;
        string value_str;

        switch ((JavaTokenType) token_type)
        {
            case PT_CHAR:
            {
                type_str = "CHAR";
                value_str = cast(value, string);
                break;
            }
            case PT_STRING:
            {
                type_str = "STRING";
                value_str = cast(value, string);
                break;
            }

            case PT_IDENTIFIER:
            {
                type_str = "IDENTIFIER";
                value_str = "";
                break;
            }

            case PT_INTEGER:
            {
                type_str = "INTEGER";
                value_str = to_string(cast(value, int));
                break;
            }

            case PT_REAL:
            {
                type_str = "REAL";
                value_str = to_string(cast(value, float));
                break;
            }

            case PT_ERROR: break;

            default:  // reserved word or special character
            {
                // Reserved word
                if (!value.empty())
                {
                    value_str = cast(value, string);
                    type_str = value_str;
                }

                // Special symbol
                else
                {
                    type_str =
                        JavaToken::SPECIAL_SYMBOL_NAMES[
                                           (JavaTokenType) token_type];
                }

                break;
            }
        }

        if (token_type != (TokenType) PT_ERROR)
        {
            // Format and send a message about each token.
            Message message(TOKEN,
                            LINE_NUMBER, to_string(token->get_line_number()),
                            POSITION, to_string(token->get_position()),
                            TOKEN_TYPE, type_str,
                            TOKEN_TEXT, token->get_text(),
                            TOKEN_VALUE, value_str);
            send_message(message);
        }
        else
        {
            JavaErrorCode error_code =
                                    (JavaErrorCode) cast(value, int);
            error_handler.flag(token, error_code, this);
        }
    }

    // Send the parser summary message.
    steady_clock::time_point end_time = steady_clock::now();
    double elapsed_time =
            duration_cast<duration<double>>(end_time - start_time).count();
    Message message(PARSER_SUMMARY,
                    LINE_COUNT, to_string(last_line_number),
                    ERROR_COUNT, to_string(get_error_count()),
                    ELAPSED_TIME, to_string(elapsed_time));
    send_message(message);
}

int JavaParserTD::get_error_count() const
{
    return error_handler.get_error_count();
}

}}} // namespace wci::frontend::java
