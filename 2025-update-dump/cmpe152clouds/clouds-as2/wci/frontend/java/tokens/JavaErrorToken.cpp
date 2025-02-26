/**
 * <h1>JavaErrorToken</h1>
 *
 * <p>Java error token.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "JavaErrorToken.h"
#include "../../Token.h"
#include "../JavaToken.h"

namespace wci { namespace frontend { namespace java { namespace tokens {

using namespace std;
using namespace wci::frontend::java;

JavaErrorToken::JavaErrorToken(Source *source, JavaErrorCode error_code,
                                   string token_text)
    throw (string)
    : JavaToken(source)
{
    type = (TokenType) PT_ERROR;
    text = token_text;
    value = (int) error_code;
}

void JavaErrorToken::extract() throw (string)
{
    // do nothing
}

}}}}  // namespace wci::frontend::java::tokens
