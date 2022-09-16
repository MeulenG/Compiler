#include "Lexer.h"


using namespace std;

void Error() {
	// just an error code for now
	cout << "Error" << endl;
}

bool check_File(bool filename_Is_Valid) {
	// Check for valid file
	if (check_String_Token != "begin" && filename_Is_Valid)
	{
		Error();
	}
	else { return true; }
}

// Pretty Trivial
bool is_Space(char c) noexcept {
	switch (c)
	{
	case ' ':
	case '\t':
	case '\r':
	case '\n':
		return true;
	default:
		return false;
	}
}


// Pretty Trivial
bool is_Digit(char c) {
	switch (c)
	{
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return true;
	default:
		return false;
	}
}

// Pretty brute-force probably gonna rewrite this shit later
bool is_Identifier_Char(char c) {
	switch (c)
	{
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case '_':
		return true;
	default:
		return false;
	}
}

// Map math symbols
map<char, int> token_Map = {
	{'+', Lexer_Token::token_Kind::token_PLUS},
	{'-', Lexer_Token::token_Kind::token_MINUS},
	{'*', Lexer_Token::token_Kind::token_TIMES},
	{'/', Lexer_Token::token_Kind::token_DIVIDE},
	{'(', Lexer_Token::token_Kind::token_LPARENTHE},
	{')', Lexer_Token::token_Kind::token_RPARENTHE},
	{'[', Lexer_Token::token_Kind::token_LBRACKET},
	{']', Lexer_Token::token_Kind::token_RBRACKET},
	{'{', Lexer_Token::token_Kind::token_LCURLYBRAC},
	{'}', Lexer_Token::token_Kind::token_RCURLYBRAC},
	{'=', Lexer_Token::token_Kind::token_EQUAL},
	{',', Lexer_Token::token_Kind::token_COMMA},
	{':', Lexer_Token::token_Kind::token_COLON},
	{';', Lexer_Token::token_Kind::token_SEMICOLON},
	{'<', Lexer_Token::token_Kind::token_LTH},
	{'>', Lexer_Token::token_Kind::token_RTH},
	{'!', Lexer_Token::token_Kind::token_NOT},
	{'&&', Lexer_Token::token_Kind::token_AND},
	{'||',Lexer_Token::token_Kind::token_OR},
};

// Map keywords
map<string, int> keyword_Map = {
	{"if", Lexer_Token::token_Kind::token_IF},
	{"else", Lexer_Token::token_Kind::token_ELSE},
	{"while", Lexer_Token::token_Kind::token_WHILE},
	{"return", Lexer_Token::token_Kind::token_RETURN},
	{"int", Lexer_Token::token_Kind::token_INT},
	{"float", Lexer_Token::token_Kind::token_FLOAT},
	{"true", Lexer_Token::token_Kind::token_TRUE},
	{"false", Lexer_Token::token_Kind::token_FALSE},
	{"struct", Lexer_Token::token_Kind::token_STRUCT},
	{"start", Lexer_Token::token_Kind::token_SOF},
	{"end", Lexer_Token::token_Kind::token_EOF},
};

// Map Identifiers
map<string, int> identifiers = {
	{"define", Lexer_Token::token_Kind::token_DEFINE},
	{"enum", Lexer_Token::token_Kind::token_ENUM},
	{"function", Lexer_Token::token_Kind::token_FUNCTION},
	{"using", Lexer_Token::token_Kind::token_USING},
	{"begin", Lexer_Token::token_Kind::token_BEGIN},
	{"end", Lexer_Token::token_Kind::token_END},
};