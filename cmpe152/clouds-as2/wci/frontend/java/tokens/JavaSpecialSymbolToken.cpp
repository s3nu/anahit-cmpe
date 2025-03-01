/**
 * <h1>JavaSpecialSymbolToken</h1>
 *
 * <p> Java special symbol tokens.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include "JavaSpecialSymbolToken.h"
#include "../JavaError.h"

namespace wci { namespace frontend { namespace java { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::java;

JavaSpecialSymbolToken::JavaSpecialSymbolToken(Source *source) throw (string)
    : JavaToken(source)
{
    extract();
}

void JavaSpecialSymbolToken::extract() throw (string)
{
    char current_ch = current_char();
    bool good_symbol = true;

    text = current_ch;

    switch (current_ch)
    {
        case '~':  case '@':  case ':':  case ';':  
        case '?':  case '.':  case ',':  case '\'':
		case '"':  case '(':  case ')':  case '[':  
		case ']':  case '{':  case '}':  
        {
            next_char();  // consume character
            break;
        }

        // << or <= or <<=
        case '<':
        {
            current_ch = next_char();  // consume '<';

            if (current_ch == '=')
            {
                text += current_ch;
                next_char();  // consume '='
            }
            else if (current_ch == '<')
            {
                text += current_ch;
                current_ch = next_char();  // consume '<'
				
				if(current_ch == '='){
					text += current_ch;
					next_char();
				}
            }

            break;
        }

        // >> or >= or >>=
        case '>':
        {
            current_ch = next_char();  // consume '>';

            if (current_ch == '=')
            {
                text += current_ch;
                next_char();  // consume '='
            }
			else if (current_ch == '>')
			{
				text += current_ch;
				current_ch = next_char();

				if(current_ch == '='){
					text += current_ch;
					next_char();
				}
				
			}

            break;
        }
		
		// ++ or +=
		case '+':
		{
			current_ch = next_char();
			
			if (current_ch == '+')
			{
				text += current_ch;
				next_char();
			}
			else if (current_ch == '=')
			{
				text += current_ch;
				next_char();
			}
			
			break;
		}
			
		// -- or -=
		case '-':
		{
			current_ch = next_char();
			
			if (current_ch == '-')
			{
				text += current_ch;
				next_char();
			}
			else if (current_ch == '=')
			{
				text += current_ch;
				next_char();
			}
			
			break;
		}
			
		// *= or */
		case '*':
		{
			current_ch = next_char();
			
			if (current_ch == '=')
			{
				text += current_ch;
				next_char();
			}
			else if (current_ch == '/')
			{
				text += current_ch;
				next_char();
			}
			
			break;
		}
			
		case '/': break;	
		// /= or // or /*
/*		case '/':
		{
			current_ch = next_char();
			
			if (current_ch == '=')
			{
				text += current_ch;
				next_char();
			}
			else if (current_ch == '/')
			{
				text += current_ch;
				next_char();
			}
			else if (current_ch == '*')
			{
				text += current_ch;
				next_char();
			}
			
			break;
		}
*/			
		// ==
		case '=':
		{
			current_ch = next_char();
			
			if (current_ch == '=')
			{
				text += current_ch;
				next_char();
			}
			
			break;
		}
			
		// |= or ||
		case '|':
		{
			current_ch = next_char();
			
			if (current_ch == '=')
			{
				text += current_ch;
				next_char();
			}
			else if (current_ch == '|')
			{
				text += current_ch;
				next_char();
			}
			
			break;
		}
			
		// %=
		case '%':
		{
			current_ch = next_char();
			
			if (current_ch == '=')
			{
				text += current_ch;
				next_char();
			}
			
			break;
		}
			
		// &= or &&
		case '&':
		{
			current_ch = next_char();
			
			if (current_ch == '=')
			{
				text += current_ch;
				next_char();
			}
			else if (current_ch == '&')
			{
				text += current_ch;
				next_char();
			}
			
			break;
		}
			
		// ^=
		case '^':
		{
			current_ch = next_char();
			
			if (current_ch == '=')
			{
				text += current_ch;
				next_char();
			}
			
			break;
		}
			
		//!=
		case '!':
		{
			current_ch = next_char();
			
			if (current_ch == '=')
			{
				text += current_ch;
				next_char();
			}
			
			break;
		}


        default:
        {
            next_char();  // consume bad character
            type = (TokenType) (PT_ERROR);
            value = (int) INVALID_CHARACTER;
            good_symbol = false;
        }
    }

    // Set the type if it wasn't an error.
    if (good_symbol) {
        type = (TokenType) (JavaToken::SPECIAL_SYMBOLS[text]);
    }
}

}}}}  // namespace wci::frontend::java::tokens
