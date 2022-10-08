#include "Parser.h"
#include "../Ast/Ast.h"
#include "../Lexer/Lexer.h"
#include "../Ast/Ast.h"
#include "../CodeGen/CodeGen.h"

using namespace std;

Lexer lex;

// Gets the next token
Token Parser::get_Next_Token() noexcept 
{
	peek();
	get();
}
// Holds our current token
Token Parser::current_Token() noexcept 
{
	lex.next();
}

// Map Precedence for binary operators.
std::map<int, Token> op_Precedence = 
{
	{1, Token::Kind::Equal},
	{2, Token::Kind::LessThan},
	{2, Token::Kind::GreaterThan},
	{3, Token::Kind::Plus},
	{3, Token::Kind::Minus},
	{4, Token::Kind::Asterisk},
	{4, Token::Kind::Slash}
};

Token Parser::install_BinOP_Precedence() noexcept 
{

}


Token parse_Num_Literals() noexcept 
{

}

// Parse Numeric Literals like "1.0"
unique_ptr<Expression> ParseLiteralNumExpre()
{
	double num_Literal;
	num_Literal = static_cast<int>(Token::Kind::Number);
	auto result = make_unique<decimal_Number_Expression>(num_Literal);
	get_Next_Token();
	return move(result);
}

// Parse Integers like "1"
unique_ptr<Expression> ParseIntegersExpre()
{
	int num_Int;
	num_Int = static_cast<int>(Token::Kind::Number);
	auto result = make_unique<decimal_Number_Expression>(num_Int);
	get_Next_Token();
	return move(result);
}
