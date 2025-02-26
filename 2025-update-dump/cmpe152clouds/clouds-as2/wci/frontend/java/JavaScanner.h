/**
 * <h1>JavaScanner</h1>
 *
 * <p>The Java scanner.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_JAVA_JAVASCANNER_H_
#define WCI_FRONTEND_JAVA_JAVASCANNER_H_

#include "../Scanner.h"
#include "../Source.h"
#include "../Token.h"

namespace wci { namespace frontend { namespace java {

using namespace std;
using namespace wci::frontend;

class JavaScanner : public Scanner
{
public:
    /**
     * Constructor
     * @param source the source to be used with this scanner.
     */
    JavaScanner(Source *source);

protected:
    /**
     * Extract and return the next Java token from the source.
     * @return the next token.
     * @throw a string message if an error occurred.
     */
    Token *extract_token() throw (string);

private:
    /**
     * Skip whitespace characters by consuming them.  A comment is whitespace.
     * @throw a string message if an error occurred.
     */
    Token* skip_white_space() throw (string);
};

}}} // namespace wci::frontend::java

#endif /* WCI_FRONTEND_JAVA_JAVASCANNER_H_ */
