/**
 * <h1>JavaToken</h1>
 *
 * <p>Base class for Java token classes.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <vector>
#include <map>
#include "JavaToken.h"

namespace wci { namespace frontend { namespace java {

	using namespace std;

	map<string, JavaTokenType> JavaToken::RESERVED_WORDS;
	map<string, JavaTokenType> JavaToken::SPECIAL_SYMBOLS;
	map<JavaTokenType, string> JavaToken::SPECIAL_SYMBOL_NAMES;

	bool JavaToken::INITIALIZED = false;

	void JavaToken::initialize()
	{
		if (INITIALIZED) return;

		vector<string> rw_strings =
		{
			"abstract", "double", "int", "long",
			"break", "else", "switch",
			"case", "enum", "native", "super",
			"char", "extends", "return", "this",
			"class", "float", "short", "throw",
			"const", "for", "package", "void",
			"continue", "goto", "protected", "volatile",
			"do", "if", "static", "while",

		};

		vector<JavaTokenType> rw_keys =
		{
			JavaTokenType::ABSTRACT,
			JavaTokenType::DOUBLE,
			JavaTokenType::INT,
			JavaTokenType::LONG,
			JavaTokenType::BREAK,
			JavaTokenType::ELSE,
			JavaTokenType::SWITCH,
			JavaTokenType::CASE,
			JavaTokenType::ENUM,
			JavaTokenType::NATIVE,
			JavaTokenType::SUPER,
			JavaTokenType::CHAR,
			JavaTokenType::EXTENDS,
			JavaTokenType::RETURN,
			JavaTokenType::THIS,
			JavaTokenType::CLASS,
			JavaTokenType::FLOAT,
			JavaTokenType::SHORT,
			JavaTokenType::THROW,
			JavaTokenType::CONST,
			JavaTokenType::FOR,
			JavaTokenType::PACKAGE,
			JavaTokenType::VOID,
			JavaTokenType::CONTINUE,
			JavaTokenType::GOTO,
			JavaTokenType::PROTECTED,
			JavaTokenType::VOLATILE,
			JavaTokenType::DO,
			JavaTokenType::IF,
			JavaTokenType::STATIC,
			JavaTokenType::WHILE,
		};

		for (int i = 0; i < rw_strings.size(); i++)
		{
			RESERVED_WORDS[rw_strings[i]] = rw_keys[i];
		}

		vector<string> ss_strings =
		{
			"+", "-", "*", "/", ".", ",", ";", ":", "'", "=",
			"<", "<=", ">=", ">", "(", ")", "[", "]", "{", "}", "^",
			"~", "!", "@", "%", "&",
			"|", "?", "\"",
			"++", "--", "<<", ">>", "+=", "-=", "*=", "/=",
			"==", "|=", "%=", "&=", "^=", "!=", "<<=", ">>=", "||", "&&",
			"//", "/*", "*/", 
			};



vector<JavaTokenType> ss_keys =
{
	JavaTokenType::PLUS,
	JavaTokenType::MINUS,
	JavaTokenType::STAR,
	JavaTokenType::SLASH,
	JavaTokenType::DOT,
	JavaTokenType::COMMA,
	JavaTokenType::SEMICOLON,
	JavaTokenType::COLON,
	JavaTokenType::QUOTE,
	JavaTokenType::EQUALS,

	JavaTokenType::LESS_THAN,
	JavaTokenType::LESS_EQUALS,
	JavaTokenType::GREATER_EQUALS,
	JavaTokenType::GREATER_THAN,
	JavaTokenType::LEFT_PAREN,
	JavaTokenType::RIGHT_PAREN,
	JavaTokenType::LEFT_BRACKET,
	JavaTokenType::RIGHT_BRACKET,
	JavaTokenType::LEFT_BRACE,
	JavaTokenType::RIGHT_BRACE,
	JavaTokenType::HAT,

	JavaTokenType::TILDE,
	JavaTokenType::EXCLAMATION_POINT,
	JavaTokenType::AT,
	JavaTokenType::MODULUS,
	JavaTokenType::BITWISE_AND,

	JavaTokenType::BITWISE_OR,
	JavaTokenType::QUESTION_MARK,
	JavaTokenType::DOUBLE_QUOTE,

	JavaTokenType::INCREMENT,
	JavaTokenType::DECREMENT,
	JavaTokenType::SHIFT_LEFT,
	JavaTokenType::SHIFT_RIGHT,
	JavaTokenType::INCREMENT_EQUALS,
	JavaTokenType::DECRMENT_EQUALS,
	JavaTokenType::MULTIPLY_EQUALS,
	JavaTokenType::DIVIDE_EQUALS,

	JavaTokenType::EQUAL_EQUALS,
	JavaTokenType::BITWISE_OR_EQUALS,
	JavaTokenType::MODULUS_EQUAL,
	JavaTokenType::BITWISE_AND_EQUALS,
	JavaTokenType::HAT_EQUALS,
	JavaTokenType::NOT_EQUALS,
	JavaTokenType::LSHIFT_EQUALS,
	JavaTokenType::RSHIFT_EQUALS,
	JavaTokenType::CONDITIONAL_OR,
	JavaTokenType::CONDITIONAL_AND,

	JavaTokenType::DOUBLE_SLASH,
	JavaTokenType::SLASH_STAR,
	JavaTokenType::STAR_SLASH
};

for (int i = 0; i < ss_strings.size(); i++)
{
	SPECIAL_SYMBOLS[ss_strings[i]] = ss_keys[i];
}

vector<string> ss_names =
{
	"PLUS", "MINUS", "STAR", "SLASH", "DOT", "COMMA",
	"SEMICOLON", "COLON", "QUOTE", "EQUALS",

	"LESS_THAN", "LESS_EQUALS", "GREATER_EQUALS", "GREATER_THAN",
	"LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET", "RIGHT_BRACKET",
	"LEFT_BRACE", "RIGHT_BRACE", "HAT",
	
	"TILDE", "EXCLAMATION_POINT", "AT", "MODULUS", "BITWISE_AND",

	"BITWISE_OR", "QUESTION_MARK", "DOUBLE_QUOTE",
	
	"INCREMENT","DECREMENT", "SHIFT_LEFT", "SHIFT_RIGHT", "INCREMENT_EQUALS",
	"DECREMENT_EQUALS", "MULTIPLY_EQUALS","DIVIDE_EQUALS",
	
	"EQUAL_EQUALS", "BITWISE_OR_EQUALS","MODULUS_EQUALS","BITWISE_AND_EQUALS", "HAT",
	"NOT_EQUALS", "LSHIFT_EQUALS","RSHIFT_EQUALS", "CONDITIONAL_OR", "CONDITIONAL_AND",
	
	"DOUBLE_SLASH", "SLASH_STAR", "STAR_SLASH"
};

for (int i = 0; i < ss_strings.size(); i++)
{
	SPECIAL_SYMBOL_NAMES[ss_keys[i]] = ss_names[i];
}

INITIALIZED = true;
}

JavaToken::JavaToken(Source *source) throw (string)
: Token(source)
{
	initialize();
}

}}}  // namespace wci::frontend::java
