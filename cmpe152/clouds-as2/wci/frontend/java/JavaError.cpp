/**
 * <h1>JavaError</h1>
 *
 * <p>Java translation errors.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <vector>
#include <map>
#include "JavaError.h"

namespace wci { namespace frontend { namespace java {

using namespace std;

bool JavaError::INITIALIZED = false;

map<JavaErrorCode, string> JavaError::SYNTAX_ERROR_MESSAGES;

void JavaError::initialize()
{
    if (INITIALIZED) return;

    vector<JavaErrorCode> error_codes =
    {
        JavaErrorCode::ALREADY_FORWARDED,
        JavaErrorCode::CASE_CONSTANT_REUSED,
        JavaErrorCode::IDENTIFIER_REDEFINED,
        JavaErrorCode::IDENTIFIER_UNDEFINED,
        JavaErrorCode::INCOMPATIBLE_ASSIGNMENT,
        JavaErrorCode::INCOMPATIBLE_TYPES,
        JavaErrorCode::INVALID_ASSIGNMENT,
        JavaErrorCode::INVALID_CHARACTER,
        JavaErrorCode::INVALID_CONSTANT,
        JavaErrorCode::INVALID_EXPONENT,
        JavaErrorCode::INVALID_EXPRESSION,
        JavaErrorCode::INVALID_FIELD,
        JavaErrorCode::INVALID_FRACTION,
        JavaErrorCode::INVALID_IDENTIFIER_USAGE,
        JavaErrorCode::INVALID_INDEX_TYPE,
        JavaErrorCode::INVALID_NUMBER,
        JavaErrorCode::INVALID_STATEMENT,
        JavaErrorCode::INVALID_SUBRANGE_TYPE,
        JavaErrorCode::INVALID_TARGET,
        JavaErrorCode::INVALID_TYPE,
        JavaErrorCode::INVALID_VAR_PARM,
        JavaErrorCode::MIN_GT_MAX,
        JavaErrorCode::MISSING_BEGIN,
        JavaErrorCode::MISSING_COLON,
        JavaErrorCode::MISSING_COLON_EQUALS,
        JavaErrorCode::MISSING_COMMA,
        JavaErrorCode::MISSING_CONSTANT,
        JavaErrorCode::MISSING_DO,
        JavaErrorCode::MISSING_DOT_DOT,
        JavaErrorCode::MISSING_END,
        JavaErrorCode::MISSING_EQUALS,
        JavaErrorCode::MISSING_FOR_CONTROL,
        JavaErrorCode::MISSING_IDENTIFIER,
        JavaErrorCode::MISSING_LEFT_BRACKET,
        JavaErrorCode::MISSING_OF,
        JavaErrorCode::MISSING_PERIOD,
        JavaErrorCode::MISSING_PROGRAM,
        JavaErrorCode::MISSING_RIGHT_BRACKET,
        JavaErrorCode::MISSING_RIGHT_PAREN,
        JavaErrorCode::MISSING_SEMICOLON,
        JavaErrorCode::MISSING_THEN,
        JavaErrorCode::MISSING_TO_DOWNTO,
        JavaErrorCode::MISSING_UNTIL,
        JavaErrorCode::MISSING_VARIABLE,
        JavaErrorCode::NOT_CONSTANT_IDENTIFIER,
        JavaErrorCode::NOT_RECORD_VARIABLE,
        JavaErrorCode::NOT_TYPE_IDENTIFIER,
        JavaErrorCode::RANGE_INTEGER,
        JavaErrorCode::RANGE_REAL,
        JavaErrorCode::STACK_OVERFLOW,
        JavaErrorCode::TOO_MANY_LEVELS,
        JavaErrorCode::TOO_MANY_SUBSCRIPTS,
        JavaErrorCode::UNEXPECTED_EOF,
        JavaErrorCode::UNEXPECTED_TOKEN,
        JavaErrorCode::UNIMPLEMENTED,
        JavaErrorCode::UNRECOGNIZABLE,
        JavaErrorCode::WRONG_NUMBER_OF_PARMS,

        // Fatal errors.
        JavaErrorCode::IO_ERROR,
        JavaErrorCode::TOO_MANY_ERRORS
    };

    vector<string> error_messages =
    {
        "Already specified in FORWARD",
        "CASE constant reused",
        "Redefined identifier",
        "Undefined identifier",
        "Incompatible assignment",
        "Incompatible types",
        "Invalid assignment statement",
        "Invalid character",
        "Invalid constant",
        "Invalid exponent",
        "Invalid expression",
        "Invalid field",
        "Invalid fraction",
        "Invalid identifier usage",
        "Invalid index type",
        "Invalid number",
        "Invalid statement",
        "Invalid subrange type",
        "Invalid assignment target",
        "Invalid type",
        "Invalid VAR parameter",
        "Min limit greater than max limit",
        "Missing BEGIN",
        "Missing :",
        "Missing :=",
        "Missing ,",
        "Missing constant",
        "Missing DO",
        "Missing ..",
        "Missing END",
        "Missing =",
        "Invalid FOR control variable",
        "Missing identifier",
        "Missing [",
        "Missing OF",
        "Missing .",
        "Missing PROGRAM",
        "Missing ]",
        "Missing )",
        "Missing ;",
        "Missing THEN",
        "Missing TO or DOWNTO",
        "Missing UNTIL",
        "Missing variable",
        "Not a constant identifier",
        "Not a record variable",
        "Not a type identifier",
        "Integer literal out of range",
        "Real literal out of range",
        "Stack overflow",
        "Nesting level too deep",
        "Too many subscripts",
        "Unexpected end of file",
        "Unexpected token",
        "Unimplemented feature",
        "Unrecognizable input",
        "Wrong number of actual parameters",

        // Fatal errors.
        "Object I/O error",
        "Too many syntax errors"
    };

    for (int i = 0; i < error_codes.size(); i++)
    {
        SYNTAX_ERROR_MESSAGES[error_codes[i]] = error_messages[i];
    }

    INITIALIZED = true;
}

}}}  // namespace wci::frontend::java
