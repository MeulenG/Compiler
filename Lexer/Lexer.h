#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Tokens for our program
enum ProgramTokens
{
	// Identifier
	token_IDENTIFIER = 0, // identifiers
	// Digits
	token_DIGIT = 1, // digit
	// Math Symbols
	token_LPARENTHE = 2, // (
	token_RPARENTHE = 3, // )
	token_LBRACKET = 4, // [
	token_RBRACKET = 5, // ]
	token_LCURLYBRAC = 6, // {
	token_RCURLYBRAC = 7, // }
	token_EQUAL = 8, // =
	token_COMMA = 9, // ,
	token_COLON = 10,// :
	token_SEMICOLON = 11,// ;
	token_PLUS = 12,
	token_MINUS = 13,
	token_TIMES = 14,
	token_DIVIDE = 15,
	token_ARROW = 16, // =>
	token_DEQ = 17, // ==
	token_LTH = 18, // <
	token_RTH = 19, // >
	token_AND = 20, // &&
	token_OR = 21, // ||
	token_NOT = 22, // !
	// keywords
	token_IF = 23,
	token_THEN = 24,
	token_ELSE = 25,
	token_INT = 26,
	token_TRUE = 27,
	token_FALSE = 28,
	token_STRUCT = 29,
	token_ENUM = 30,
	token_FUNCTION = 31,
	token_DEFINE = 32,
	token_USING = 33,
	// string
	token_QUOTE = 34, // ""
	// Validate file
	token_SOF = 35, // start of file
	token_EOF = 36, // end of file
};

#endif