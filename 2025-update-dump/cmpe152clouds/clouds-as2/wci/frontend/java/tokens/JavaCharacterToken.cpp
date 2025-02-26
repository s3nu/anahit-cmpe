//  *
//  * <p> Java string tokens.</p>
//  *
//  * <p>Copyright (c) 2017 by Ronald Mak</p>
//  * <p>For instructional purposes only.  No warranties.</p>

#include "JavaCharacterToken.h"
#include "../JavaError.h"
#include <string>

namespace wci { namespace frontend { namespace java { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::java;

JavaCharacterToken::JavaCharacterToken(Source *source) throw (string)
    : JavaToken(source)
{
    extract();
}
void JavaCharacterToken::extract() throw (string)
{
    string value_str = "";

    char current_ch = next_char();
    text += "\'";
    do
    {
        if ((current_ch != '\'') && (current_ch != Source::END_OF_FILE) && (current_ch != '\\')) {
            text += current_ch;
            value_str  += current_ch;
            current_ch = next_char();
        }
        if (current_ch == '\\') {
            text  += current_ch;
            current_ch = next_char();

            if(current_ch == 't')
                value_str += '\t';
            else if(current_ch == 'n')
                value_str += '\n';
            else
                value_str += current_ch;
            text  += current_ch;
            current_ch = next_char();
        }
    } while((current_ch != '\'') && (current_ch != Source::END_OF_FILE));

    if (current_ch == '\'') {
        next_char();
        text += '\'';
        type = (TokenType) PT_CHAR;
        value = value_str;
    }
    else {
        type = (TokenType) PT_ERROR;
        value = ((int) UNEXPECTED_EOF);
    }
}
}}}} // namespace wci::frontend::pascal::tokens