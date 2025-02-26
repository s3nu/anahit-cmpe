/**
 * <h1>JavaError</h1>
 *
 * <p>Java translation errors.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_JAVA_JAVAERROR_H_
#define WCI_FRONTEND_JAVA_JAVAERROR_H_

#include <string>
#include <map>

namespace wci { namespace frontend { namespace java {

using namespace std;

/**
 * Java error codes.
 */
enum class JavaErrorCode
{
    ALREADY_FORWARDED,
    CASE_CONSTANT_REUSED,
    IDENTIFIER_REDEFINED,
    IDENTIFIER_UNDEFINED,
    INCOMPATIBLE_ASSIGNMENT,
    INCOMPATIBLE_TYPES,
    INVALID_ASSIGNMENT,
    INVALID_CHARACTER,
    INVALID_CONSTANT,
    INVALID_EXPONENT,
    INVALID_EXPRESSION,
    INVALID_FIELD,
    INVALID_FRACTION,
    INVALID_IDENTIFIER_USAGE,
    INVALID_INDEX_TYPE,
    INVALID_NUMBER,
    INVALID_STATEMENT,
    INVALID_SUBRANGE_TYPE,
    INVALID_TARGET,
    INVALID_TYPE,
    INVALID_VAR_PARM,
    MIN_GT_MAX,
    MISSING_BEGIN,
    MISSING_COLON,
    MISSING_COLON_EQUALS,
    MISSING_COMMA,
    MISSING_CONSTANT,
    MISSING_DO,
    MISSING_DOT_DOT,
    MISSING_END,
    MISSING_EQUALS,
    MISSING_FOR_CONTROL,
    MISSING_IDENTIFIER,
    MISSING_LEFT_BRACKET,
    MISSING_OF,
    MISSING_PERIOD,
    MISSING_PROGRAM,
    MISSING_RIGHT_BRACKET,
    MISSING_RIGHT_PAREN,
    MISSING_SEMICOLON,
    MISSING_THEN,
    MISSING_TO_DOWNTO,
    MISSING_UNTIL,
    MISSING_VARIABLE,
    NOT_CONSTANT_IDENTIFIER,
    NOT_RECORD_VARIABLE,
    NOT_TYPE_IDENTIFIER,
    RANGE_INTEGER,
    RANGE_REAL,
    STACK_OVERFLOW,
    TOO_MANY_LEVELS,
    TOO_MANY_SUBSCRIPTS,
    UNEXPECTED_EOF,
    UNEXPECTED_TOKEN,
    UNIMPLEMENTED,
    UNRECOGNIZABLE,
    WRONG_NUMBER_OF_PARMS,

    // Fatal errors.
    IO_ERROR,
    TOO_MANY_ERRORS
};

constexpr JavaErrorCode ALREADY_FORWARDED = JavaErrorCode::ALREADY_FORWARDED;
constexpr JavaErrorCode CASE_CONSTANT_REUSED = JavaErrorCode::CASE_CONSTANT_REUSED;
constexpr JavaErrorCode IDENTIFIER_REDEFINED = JavaErrorCode::IDENTIFIER_REDEFINED;
constexpr JavaErrorCode IDENTIFIER_UNDEFINED = JavaErrorCode::IDENTIFIER_UNDEFINED;
constexpr JavaErrorCode INCOMPATIBLE_ASSIGNMENT = JavaErrorCode::INCOMPATIBLE_ASSIGNMENT;
constexpr JavaErrorCode INCOMPATIBLE_TYPES = JavaErrorCode::INCOMPATIBLE_TYPES;
constexpr JavaErrorCode INVALID_ASSIGNMENT = JavaErrorCode::INVALID_ASSIGNMENT;
constexpr JavaErrorCode INVALID_CHARACTER = JavaErrorCode::INVALID_CHARACTER;
constexpr JavaErrorCode INVALID_CONSTANT = JavaErrorCode::INVALID_CONSTANT;
constexpr JavaErrorCode INVALID_EXPONENT = JavaErrorCode::INVALID_EXPONENT;
constexpr JavaErrorCode INVALID_EXPRESSION = JavaErrorCode::INVALID_EXPRESSION;
constexpr JavaErrorCode INVALID_FIELD = JavaErrorCode::INVALID_FIELD;
constexpr JavaErrorCode INVALID_FRACTION = JavaErrorCode::INVALID_FRACTION;
constexpr JavaErrorCode INVALID_IDENTIFIER_USAGE = JavaErrorCode::INVALID_IDENTIFIER_USAGE;
constexpr JavaErrorCode INVALID_INDEX_TYPE = JavaErrorCode::INVALID_INDEX_TYPE;
constexpr JavaErrorCode INVALID_NUMBER = JavaErrorCode::INVALID_NUMBER;
constexpr JavaErrorCode INVALID_STATEMENT = JavaErrorCode::INVALID_STATEMENT;
constexpr JavaErrorCode INVALID_SUBRANGE_TYPE = JavaErrorCode::INVALID_SUBRANGE_TYPE;
constexpr JavaErrorCode INVALID_TARGET = JavaErrorCode::INVALID_TARGET;
constexpr JavaErrorCode INVALID_TYPE = JavaErrorCode::INVALID_TYPE;
constexpr JavaErrorCode INVALID_VAR_PARM = JavaErrorCode::INVALID_VAR_PARM;
constexpr JavaErrorCode MIN_GT_MAX = JavaErrorCode::MIN_GT_MAX;
constexpr JavaErrorCode MISSING_BEGIN = JavaErrorCode::MISSING_BEGIN;
constexpr JavaErrorCode MISSING_COLON = JavaErrorCode::MISSING_COLON;
constexpr JavaErrorCode MISSING_COMMA = JavaErrorCode::MISSING_COMMA;
constexpr JavaErrorCode MISSING_CONSTANT = JavaErrorCode::MISSING_CONSTANT;
constexpr JavaErrorCode MISSING_DO = JavaErrorCode::MISSING_DO;
constexpr JavaErrorCode MISSING_DOT_DOT = JavaErrorCode::MISSING_DOT_DOT;
constexpr JavaErrorCode MISSING_END = JavaErrorCode::MISSING_END;
constexpr JavaErrorCode MISSING_EQUALS = JavaErrorCode::MISSING_EQUALS;
constexpr JavaErrorCode MISSING_COLON_EQUALS = JavaErrorCode::MISSING_COLON_EQUALS;
constexpr JavaErrorCode MISSING_FOR_CONTROL = JavaErrorCode::MISSING_FOR_CONTROL;
constexpr JavaErrorCode MISSING_IDENTIFIER = JavaErrorCode::MISSING_IDENTIFIER;
constexpr JavaErrorCode MISSING_LEFT_BRACKET = JavaErrorCode::MISSING_LEFT_BRACKET;
constexpr JavaErrorCode MISSING_OF = JavaErrorCode::MISSING_OF;
constexpr JavaErrorCode MISSING_PERIOD = JavaErrorCode::MISSING_PERIOD;
constexpr JavaErrorCode MISSING_PROGRAM = JavaErrorCode::MISSING_PROGRAM;
constexpr JavaErrorCode MISSING_RIGHT_BRACKET = JavaErrorCode::MISSING_RIGHT_BRACKET;
constexpr JavaErrorCode MISSING_RIGHT_PAREN = JavaErrorCode::MISSING_RIGHT_PAREN;
constexpr JavaErrorCode MISSING_SEMICOLON = JavaErrorCode::MISSING_SEMICOLON;
constexpr JavaErrorCode MISSING_THEN = JavaErrorCode::MISSING_THEN;
constexpr JavaErrorCode MISSING_TO_DOWNTO = JavaErrorCode::MISSING_TO_DOWNTO;
constexpr JavaErrorCode MISSING_UNTIL = JavaErrorCode::MISSING_UNTIL;
constexpr JavaErrorCode MISSING_VARIABLE = JavaErrorCode::MISSING_VARIABLE;
constexpr JavaErrorCode NOT_CONSTANT_IDENTIFIER = JavaErrorCode::NOT_CONSTANT_IDENTIFIER;
constexpr JavaErrorCode NOT_RECORD_VARIABLE = JavaErrorCode::NOT_RECORD_VARIABLE;
constexpr JavaErrorCode NOT_TYPE_IDENTIFIER = JavaErrorCode::NOT_TYPE_IDENTIFIER;
constexpr JavaErrorCode RANGE_INTEGER = JavaErrorCode::RANGE_INTEGER;
constexpr JavaErrorCode RANGE_REAL = JavaErrorCode::RANGE_REAL;
constexpr JavaErrorCode STACK_OVERFLOW = JavaErrorCode::STACK_OVERFLOW;
constexpr JavaErrorCode TOO_MANY_LEVELS = JavaErrorCode::TOO_MANY_LEVELS;
constexpr JavaErrorCode TOO_MANY_SUBSCRIPTS = JavaErrorCode::TOO_MANY_SUBSCRIPTS;
constexpr JavaErrorCode UNEXPECTED_EOF = JavaErrorCode::UNEXPECTED_EOF;
constexpr JavaErrorCode UNEXPECTED_TOKEN = JavaErrorCode::UNEXPECTED_TOKEN;
constexpr JavaErrorCode UNIMPLEMENTED = JavaErrorCode::UNIMPLEMENTED;
constexpr JavaErrorCode UNRECOGNIZABLE = JavaErrorCode::UNRECOGNIZABLE;
constexpr JavaErrorCode WRONG_NUMBER_OF_PARMS = JavaErrorCode::WRONG_NUMBER_OF_PARMS;

constexpr JavaErrorCode IO_ERROR = JavaErrorCode::IO_ERROR;
constexpr JavaErrorCode TOO_MANY_ERRORS = JavaErrorCode::TOO_MANY_ERRORS;

class JavaError
{
public:
    static map<JavaErrorCode, string> SYNTAX_ERROR_MESSAGES;

    /**
     * Initialize the static map.
     */
    static void initialize();

private:
    static bool INITIALIZED;
};

}}}  // namespace wci::frontend::java

#endif /* WCI_FRONTEND_JAVA_JAVAERROR_H_ */
