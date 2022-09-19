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
	// Create a vector to store the tokens
	vector<string> Token;
	// tokenize
	void tokenize(string filename);
		
public:
	bool is_Space(char c);
	bool is_Digit(char c);
	bool is_decimal(char c);
	bool is_Identifier_Char(char c);
	int check_File(bool filename_Is_Valid);
	
public:
	enum class token_Kind
	{
		// Numbers, floats etc
		Number,
		// Identifiers
		Identifier,
		// String
		SingleQuote,
		DoubleQuote,
		// Brackets
		LPAREN,
		RPAREN,
		LSQUAREBRAC,
		RSQUAREBRAC,
		LCURLYBRAC,
		RCURLYBRAC,
		// Math Symbols
		PLUS,
		MINUS,
		MULTIPLY,
		DIVIDE,
		ARROW_RIGHT, // >
		ARROW_LEFT, // <
		EQUAL,
		PIPE,
		AND,
		OR,
		NOT,
		DOT,
		// Keywords
		IF,
		THEN,
		ELSE,
		WHILE,
		DEFINE,
		INT,
		// Bools
		TRUE,
		FALSE,
		// File
		SOF,
		END,
		// Error
		UNRECOGNIZED,
		UNEXPECTED,
		// Comments
		Comment,
		Comma,
		Colon,
		SemiColon,
};
		
	Lexer_Token(token_Kind kind) noexcept : m_kind { kind } {}

	Lexer_Token(token_Kind kind, const char* begin, size_t len) noexcept : m_kind{kind}, m_lexeme(begin, len) {}
	
	Lexer_Token(token_Kind kind, const char* begin, const char* end) noexcept :  m_kind{kind}, m_lexeme(begin, distance(begin, end)) {}

	token_Kind kind() const noexcept 
	{
		return m_kind; 
	}
	
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

	// Template for the kind
	template <typename... Ts>
	bool is_One_Of(token_Kind k1, token_Kind k2, Ts... ks) const noexcept
	{
		return is(k1) || is_One_Of(k2, ks...);
	}

	string_view lexeme() const noexcept
	{
		return m_lexeme;
	}
	
	void lexeme(string_view lexeme) noexcept 
	{
		m_lexeme = move(lexeme);
	}

private:
	token_Kind m_kind{};
	string_view m_lexeme{};
};

class Lexer
{
	public:
	Lexer(const char* begin) noexcept : m_begin{begin} {}

	Lexer_Token next_Token() noexcept;
	
	private:
	Lexer_Token Identifier() noexcept;
	
	Lexer_Token Number() noexcept;
	
	Lexer_Token comments() noexcept;
	
	Lexer_Token atom(Lexer_Token::token_Kind) noexcept;
	
	char peek() const noexcept
	{
		return *m_begin;
	}
	
	char get() noexcept 
	{
		return *m_begin++;
	}

	const char* m_begin = nullptr; 
}; 

#endif