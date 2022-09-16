#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <filesystem>
#include <fstream>

using namespace std;
// Global Variables for our Lexer
string check_String_Token;
double check_Number_Token; // Check Decimal values like "1.0"
int check_Number_Token_Int; // Check Integers like "1"


class Lexer_Token
{
public:
	virtual ~Lexer_Token();
	bool filename_Is_Valid(string filename) { }
	// Create a vector to store the tokens
	vector<string> Token;
	// tokenize
	void tokenize(string filename);
		
public:
	bool is_Space(char c) { }
	bool is_Digit(char c) { }
	bool is_Identifier_Char(char c) { }
	int check_File(bool filename_Is_Valid) {  }
	int split_Program_To_Tokens() {  }
		
public:
	enum token_Kind
	{
	// Identifier
	token_IDENTIFIER = 0, // identifiers
	// Numbers
	token_DIGIT = 1,
	token_NUM_LITERAL = 2, // Literal
	token_INTEGER = 3, // Integer
	// Math Symbols
	token_LPARENTHE = 4, // (
	token_RPARENTHE = 5, // )
	token_LBRACKET = 6, // [
	token_RBRACKET = 7, // ]
	token_LCURLYBRAC = 8, // {
	token_RCURLYBRAC = 9, // }
	token_EQUAL = 10, // =
	token_COMMA = 11, // ,
	token_COLON = 12,// :
	token_SEMICOLON = 13,// ;
	token_PLUS = 14,
	token_MINUS = 15,
	token_TIMES = 16,
	token_DIVIDE = 17,
	token_ARROW = 18, // =>
	token_DEQ = 19, // ==
	token_LTH = 20, // <
	token_RTH = 21, // >
	token_AND = 22, // &&
	token_OR = 23, // ||
	token_NOT = 24, // !
	// Keywords
	// Statements
	token_IF = 25,
	token_THEN = 26,
	token_ELSE = 27,
	token_WHILE = 28,
	// Int, float
	token_INT = 29,
	token_FLOAT = 30,
	token_DOUBLE = 31,
	// Bools
	token_TRUE = 32,
	token_FALSE = 33,
	// Classic struct which we all love
	token_STRUCT = 34,
	// The classic enum
	token_ENUM = 35,
	// Tokens for making a function
	token_FUNCTION = 36,
	token_BEGIN = 37,
	token_END = 38,
	token_RETURN = 39,
	// Token for defining a variable
	token_DEFINE = 40,
	// Token for importing a file or library
	token_USING = 41,
	// string
	token_QUOTE = 42, // ""
	// Validate file
	token_SOF = 43, // start of file
	token_EOF = 44, // end of file
};
		
	Lexer_Token(token_Kind kind) noexcept : m_kind { kind } {}

	Lexer_Token(token_Kind kind, const char* begin, size_t len) noexcept : m_kind{kind}, m_lexeme(begin, len) {}
	
	Lexer_Token(token_Kind kind, const char* begin, const char* end) noexcept :  m_kind{kind}, m_lexeme(begin, distance(begin, end)) {}

	token_Kind kind() const noexcept 
	{
		return m_kind; 
	}
	
	token_Kind kind() noexcept { return m_kind; }
	
	void kind(token_Kind kind) noexcept 
	{ 
		m_kind = kind; 
	}
	
	// Function to if the kind is correct or not
	bool is(token_Kind kind) const noexcept 
	{ 
		return m_kind == kind; 
	}
	
	// Function to if the kind is not correct
	bool is_not(token_Kind kind) const noexcept 
	{ 
		return m_kind != kind;
	}
	
	// Function to tell if the kind is one or the other
	bool is_One_Of(token_Kind k1, token_Kind k2) const noexcept 
	{ 
		return is(k1) || is(k2); 
	}

	
	void lexeme(string_view lexeme) noexcept 
	{
		m_lexeme = move(lexeme);
	}

private:
	token_Kind m_kind;
	string_view m_lexeme;
};

class Lexer
{
public:
	Lexer();
	~Lexer();

private:

};

Lexer::Lexer()
{
}

Lexer::~Lexer()
{
}



#endif