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
	token_EQUAL		 = 8, // =
	token_COMMA		 = 9, // ,
	token_COLON		 = 10,// :
	token_SEMICOLON	 = 11,// ;
	token_PLUS		 = 12,
	token_MINUS		 = 13,
	token_TIMES		 = 14,
	token_DIVIDE	 = 15,
	token_ARROW		 = 16, // =>
	token_DEQ		 = 17, // ==
	token_LTH		 = 18, // <
	token_RTH		 = 19, // >
	token_AND		 = 20, // &&
	token_OR		 = 21, // ||
	token_NOT		 = 22, // !
	token_IF		 = 23,
	token_ELSE		 = 24,
	token_INT		 = 25,
	token_TRUE		 = 26,
	token_FALSE		 = 27,
	token_STRUCT	 = 28,
	token_ENUM		 = 29,
	token_FUNCTION	 = 30,
	token_DEFINE	 = 31,
	token_USING		 = 32,
	token_QUOTE		 = 33, // ""
	token_SOF		 = 34, // start of file
	token_EOF		 = 35, // end of file
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
		string str_RPARENTHE = to_string(token_RPARENTHE);
		return str_RPARENTHE;
	}
	else if (Token == token_LBRACKET)
	{
		string str_LBRACKET = to_string(token_LBRACKET);
		return str_LBRACKET;
	}
	else if (Token == token_RBRACKET)
	{
		string str_RBRACKET = to_string(token_RBRACKET);
		return str_RBRACKET;
	}
	else if (Token == token_LCURLYBRAC)
	{
		string str_LCURLYBRAC = to_string(token_LCURLYBRAC);
		return str_LCURLYBRAC;
	}
	else if (Token == token_RCURLYBRAC)
	{
		string str_RCURLYBRAC = to_string(token_RCURLYBRAC);
		return str_RCURLYBRAC;
	}
	else if (Token == token_EQUAL)
	{
		string str_EQUAL = to_string(token_EQUAL);
		return str_EQUAL;
	}
	else if (Token == token_COMMA)
	{
		string str_COMMA = to_string(token_COMMA);
		return str_COMMA;
	}
	else if (Token == token_COLON)
	{
		string str_COLON = to_string(token_COLON);
		return str_COLON;
	}
	else if (Token == token_SEMICOLON)
	{
		string str_SEMICOLON = to_string(token_SEMICOLON);
		return str_SEMICOLON;
	}
	else if (Token == token_PLUS)
	{
		string str_PLUS = to_string(token_PLUS);
		return str_PLUS;
	}
	else if (Token == token_MINUS)
	{
		string str_MINUS = to_string(token_MINUS);
		return str_MINUS;
	}
	else if (Token == token_TIMES)
	{
		string str_TIMES = to_string(token_TIMES);
		return str_TIMES;
	}
	else if (Token == token_DIVIDE)
	{
		string str_DIVIDE = to_string(token_DIVIDE);
		return str_DIVIDE;
	}
	else if (Token == token_ARROW)
	{
		string str_ARROW = to_string(token_ARROW);
		return str_ARROW;
	}
	else if (Token == token_DEQ)
	{
		string str_DEQ = to_string(token_DEQ);
		return str_DEQ;
	}
	else if (Token == token_LTH)
	{
		string str_LTH = to_string(token_LTH);
		return str_LTH;
	}
	else if (Token == token_RTH)
	{
		string str_RTH = to_string(token_RTH);
		return str_RTH;
	}
	else if (Token == token_AND)
	{
		string str_AND = to_string(token_AND);
		return str_AND;
	}
	else if (Token == token_OR)
	{
		string str_OR = to_string(token_OR);
		return str_OR;
	}
	else if (Token == token_NOT)
	{
		string str_NOT = to_string(token_NOT);
		return str_NOT;
	}
	else if (Token == token_IF)
	{
		string str_IF = to_string(token_IF);
		return str_IF;
	}
	else if (Token == token_ELSE)
	{
		string str_ELSE = to_string(token_ELSE);
		return str_ELSE;
	}
	else if (Token == token_INT)
	{
		string str_INT = to_string(token_INT);
		return str_INT;
	}
	else if (Token == token_TRUE)
	{
		string str_TRUE = to_string(token_TRUE);
		return str_TRUE;
	}
	else if (Token == token_FALSE)
	{
		string str_FALSE = to_string(token_FALSE);
		return str_FALSE;
	}
	else if (Token == token_STRUCT)
	{
		string str_STRUCT = to_string(token_STRUCT);
		return str_STRUCT;
	}
	else if (Token == token_ENUM)
	{
		string str_ENUM = to_string(token_ENUM);
		return str_ENUM;
	}
	else if (Token == token_FUNCTION)
	{
		string str_FUNCTION = to_string(token_FUNCTION);
		return str_FUNCTION;
	}
	else if (Token == token_DEFINE)
	{
		string str_DEFINE = to_string(token_DEFINE);
		return str_DEFINE;
	}
	else if (Token == token_USING)
	{
		string str_USING = to_string(token_USING);
		return str_USING;
	}
	else if (Token == token_QUOTE)
	{
		string str_QUOTE = to_string(token_QUOTE);
		return str_QUOTE;
	}
	else if (Token == token_SOF)
	{
		string str_SOF = to_string(token_SOF);
		return str_SOF;
	}
	else if (Token == token_EOF)
	{
		string str_EOF = to_string(token_EOF);
		return str_EOF;
	}
	else {
	Error();
}
}

void Error() {
	// just an error code for now
	cout << "Error" << endl;
}

