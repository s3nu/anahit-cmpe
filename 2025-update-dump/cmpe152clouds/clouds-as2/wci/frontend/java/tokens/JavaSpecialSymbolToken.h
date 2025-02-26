/**
 * <h1>JavaSpecialSymbolToken</h1>
 *
 * <p> Java special symbol tokens.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_JAVA_TOKENS_JAVASPECIALSYMBOLTOKEN_H_
#define WCI_FRONTEND_JAVA_TOKENS_JAVASPECIALSYMBOLTOKEN_H_

#include <string>
#include "../JavaToken.h"

namespace wci { namespace frontend { namespace java { namespace tokens {

using namespace std;
using namespace wci::frontend::java;

class JavaSpecialSymbolToken : public JavaToken
{
public:
    /**
     * Constructor.
     * @param source the source from where to fetch the token's characters.
     * @throw a string message if an error occurred.
     */
    JavaSpecialSymbolToken(Source *source) throw (string);

protected:
    /**
     * Extract a Java special symbol token from the source.
     * Override of wci::frontend::Token.
     * @throw a string message if an error occurred.
     */
    void extract() throw (string);
};

}}}}  // namespace wci::frontend::java::tokens

#endif /* WCI_FRONTEND_JAVA_TOKENS_JAVASPECIALSYMBOLTOKEN_H_ */
