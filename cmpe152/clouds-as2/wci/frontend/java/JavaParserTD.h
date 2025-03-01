/**
 * <h1>JavaParserTD</h1>
 *
 * <p>The top-down Java parser.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_JAVA_JAVAPARSERTD_H_
#define WCI_FRONTEND_JAVA_JAVAPARSERTD_H_

#include "../Parser.h"
#include "../Scanner.h"
#include "JavaErrorHandler.h"

namespace wci { namespace frontend { namespace java {

using namespace std;
using namespace wci::frontend;

class JavaParserTD : public Parser
{
public:
    /**
     * Constructor.
     * @param scanner the scanner to be used with this parser.
     */
    JavaParserTD(Scanner *scanner);

    /**
     * Constructor for subclasses.
     * @param parent the parent parser.
     */
    JavaParserTD(JavaParserTD *parent);

    /**
     * Parse a Java source program and generate the symbol table
     * and the intermediate code.
     * Implementation of wci::frontend::Parser.
     * @throw a string message if an error occurred.
     */
    void parse() throw (string);

    /**
     * Return the number of syntax errors found by the parser.
     * Implementation of wci::frontend::Parser.
     * @return the error count.
     */
    int get_error_count() const;

protected:
    static JavaErrorHandler error_handler;
};

}}} // namespace wci::frontend::java


#endif /* WCI_FRONTEND_JAVA_JAVAPARSERTD_H_ */
