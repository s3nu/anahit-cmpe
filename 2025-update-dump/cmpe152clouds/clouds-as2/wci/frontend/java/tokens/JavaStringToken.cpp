/**
 * <h1>JavaStringToken</h1>
 *
 * <p> Java string tokens.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include "JavaStringToken.h"
#include "../JavaError.h"

namespace wci { namespace frontend { namespace java { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::java;

JavaStringToken::JavaStringToken(Source *source) throw (string)
    : JavaToken(source)
{
    extract();
}

void JavaStringToken::extract() throw (string)
{
    string value_str = "";

    char current_ch = next_char();  // consume initial quote
    text += "\"";

    // Get string characters.
    do
    {
        // Replace any whitespace character with a blank.
        if (isspace(current_ch)) current_ch = ' ';

        if((current_ch == '\\') && (peek_char() == 'n'))
        {
            text += "\\n";                 //Insert a "\n" into the text
            value_str += '\n';             // added a newline to the value string
            current_ch = next_char();
            current_ch = next_char();      // consume '\n'
        }

        if((current_ch == '\\') && (peek_char()== 't'))
        {
            text += "\\t";                   //insert a "\t" into the text
            value_str += '\t';               // added a tab to the value string
            current_ch = next_char();
            current_ch = next_char();   //consume '\t'
        }

        //Quote inside a string
        if((current_ch == '\\') && (peek_char() == '\"'))
        {

            current_ch = next_char();           //Discard  "/"
            text += current_ch;                 // Consume the first qoute (")
            value_str += current_ch;            // repeat for value_str

            current_ch = next_char();              // Discard "
        } 

        else if ((current_ch != '\"') && (current_ch != EOF))
        {
            text += current_ch;
            value_str  += current_ch;
            current_ch = next_char();  // consume character
        }


       /* // Quote?  Each pair of adjacent quotes represents a double-quote.
        if (current_ch == '\"')
        {
            while ((current_ch == '\"') && (peek_char() == '\"'))
            {
                text += """";
                value_str  += current_ch;  // append a single quote
                current_ch = next_char();  // consume pair of quotes
                current_ch = next_char();
            }
        } */
    } while ((current_ch != '\"') && (current_ch != Source::END_OF_FILE));


    if (current_ch == '\"')
    {
        next_char();  // consume final quote
        text += '\"';
        type = (TokenType) PT_STRING;
        value = value_str;
    }
    else
    {
        type = (TokenType) PT_ERROR;
        value = (int) UNEXPECTED_EOF;
    }
}

}}}} // namespace wci::frontend::java::tokens
