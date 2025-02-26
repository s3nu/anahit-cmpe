/**
 * <h1>JavaWordToken</h1>
 *
 * <p> Java word tokens (identifiers and reserved words).</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_JAVA_TOKENS_JAVAWORDTOKEN_H_
#define WCI_FRONTEND_JAVA_TOKENS_JAVAWORDTOKEN_H_

#include <string>
#include "../JavaToken.h"

namespace wci { namespace frontend { namespace java { namespace tokens {

using namespace std;
using namespace wci::frontend::java;

class JavaWordToken : public JavaToken
{
public:
    /**
     * Constructor.
     * @param source the source from where to fetch the token's characters.
     * @throw a string message if an error occurred.
     */
    JavaWordToken(Source *source) throw (string);

protected:
    /**
     * Extract a Java word token from the source.
     * Override of wci::frontend::Token.
     * @throw a string message if an error occurred.
     */
    void extract() throw (string);
};

}}}}  // namespace wci::frontend::java::tokens

#endif /* WCI_FRONTEND_JAVA_TOKENS_JAVAWORDTOKEN_H_ */
