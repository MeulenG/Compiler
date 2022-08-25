#include "Lexer.h"


using namespace std;
// Tokens for our program
enum Token
{
	token_IDENTIFIER = 0, // identifiers
	token_DIGIT		 = 1, // digit
	token_LPARENTHE	 = 2, // (
	token_RPARENTHE	 = 3, // )
	token_LBRACKET	 = 4, // [
	token_RBRACKET	 = 5, // ]
	token_LCURLYBRAC = 6, // {
	token_RCURLYBRAC = 7, // }
	token_EQUAL		 = 8, // ==
	token_COMMA		 = 9, // ,
	token_COLON		 = 10,// :
	token_SEMICOLON	 = 11,// ;
	token_STRUCT	 = 12,
	token_ENUM		 = 13,
	token_FUNCTION	 = 14,
	token_DEFINE	 = 15,
	token_USING		 = 16,
	token_QUOTE		 = 17, // ""
	token_SOF		 = 18,
	token_EOF		 = 19,
};

// When we have our token sequence, we need to convert them to strings
string convert_Token_To_String(int Token) {
	if (Token == token_IDENTIFIER)
	{
		string str_IDENTIFIER = to_string(token_IDENTIFIER);
		return str_IDENTIFIER;
	}
	else if (Token == token_DIGIT)
	{
		string str_DIGIT = to_string(token_DIGIT);
		return str_DIGIT;
	}
	else if (Token == token_LPARENTHE) 
	{
		string str_LPARENTHE = to_string(token_LPARENTHE);
		return str_LPARENTHE;
	}
	else if (Token == token_RPARENTHE)
	{

	}
}