#include "Lexer.h"

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
	return true;
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

bool is_decimal(char c) noexcept {
	switch (c) {
	case '.':
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
//map<Lexer_Token::token_Kind, string> token_Map = {
//	{'+', Lexer_Token::token_Kind::AND},
//	{'-', Lexer_Token::token_Kind::token_MINUS},
//	{'*', Lexer_Token::token_Kind::token_TIMES},
//	{'/', Lexer_Token::token_Kind::token_DIVIDE},
//	{'(', Lexer_Token::token_Kind::token_LPARENTHE},
//	{')', Lexer_Token::token_Kind::token_RPARENTHE},
//	{'[', Lexer_Token::token_Kind::token_LBRACKET},
//	{']', Lexer_Token::token_Kind::token_RBRACKET},
//	{'{', Lexer_Token::token_Kind::token_LCURLYBRAC},
//	{'}', Lexer_Token::token_Kind::token_RCURLYBRAC},
//	{'=', Lexer_Token::token_Kind::token_EQUAL},
//	{',', Lexer_Token::token_Kind::token_COMMA},
//	{':', Lexer_Token::token_Kind::token_COLON},
//	{';', Lexer_Token::token_Kind::token_SEMICOLON},
//	{'<', Lexer_Token::token_Kind::token_LTH},
//	{'>', Lexer_Token::token_Kind::token_RTH},
//	{'!', Lexer_Token::token_Kind::token_NOT},
//	{'&&', Lexer_Token::token_Kind::token_AND},
//	{'||',Lexer_Token::token_Kind::token_OR},
//};

// Map keywords
//map<string, int> keyword_Map = {
//	{"if", Lexer_Token::token_Kind::token_IF},
//	{"else", Lexer_Token::token_Kind::token_ELSE},
//	{"while", Lexer_Token::token_Kind::token_WHILE},
//	{"return", Lexer_Token::token_Kind::token_RETURN},
//	{"int", Lexer_Token::token_Kind::token_INT},
//	{"float", Lexer_Token::token_Kind::token_FLOAT},
//	{"true", Lexer_Token::token_Kind::token_TRUE},
//	{"false", Lexer_Token::token_Kind::token_FALSE},
//	{"struct", Lexer_Token::token_Kind::token_STRUCT},
//	{"start", Lexer_Token::token_Kind::token_SOF},
//	{"end", Lexer_Token::token_Kind::token_EOF},
//};
//
//// Map Identifiers
//map<string, int> identifiers = {
//	{"define", Lexer_Token::token_Kind::token_DEFINE},
//	{"enum", Lexer_Token::token_Kind::token_ENUM},
//	{"function", Lexer_Token::token_Kind::token_FUNCTION},
//	{"using", Lexer_Token::token_Kind::token_USING},
//	{"begin", Lexer_Token::token_Kind::token_BEGIN},
//	{"end", Lexer_Token::token_Kind::token_END},
//};
//

Lexer_Token Lexer::atom(Lexer_Token::token_Kind kind) noexcept
{
	return Lexer_Token(kind, m_begin++, 1);
}

Lexer_Token Lexer::next_Token() noexcept
{
	while (is_Space(peek())) get();
	{
		switch (peek()) {
			// In case of a NULL Terminator
		case '\0':
			return Lexer_Token(Lexer_Token::token_Kind::END, m_begin, 1);
		default:
			return atom(Lexer_Token::token_Kind::UNEXPECTED);
			// In case of an Identifier Character
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
			return Lexer_Token::token_Kind::Identifier;
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
			return Lexer_Token::token_Kind::Number;
		case '(':
			return atom(Lexer_Token::token_Kind::LPAREN);
		case ')':
			return atom(Lexer_Token::token_Kind::RPAREN);
		case '[':
			return atom(Lexer_Token::token_Kind::LSQUAREBRAC);
		case ']':
			return atom(Lexer_Token::token_Kind::RSQUAREBRAC);
		case '{':
			return atom(Lexer_Token::token_Kind::LCURLYBRAC);
		case '}':
			return atom(Lexer_Token::token_Kind::RCURLYBRAC);
		case '<':
			return atom(Lexer_Token::token_Kind::ARROW_LEFT);
		case '>':
			return atom(Lexer_Token::token_Kind::ARROW_RIGHT);
		case '=':
			return atom(Lexer_Token::token_Kind::EQUAL);
		case '+':
			return atom(Lexer_Token::token_Kind::PLUS);
		case '-':
			return atom(Lexer_Token::token_Kind::MINUS);
		case '*':
			return atom(Lexer_Token::token_Kind::MULTIPLY);
		case '/':
			return atom(Lexer_Token::token_Kind::Comment);
		case ',':
			return atom(Lexer_Token::token_Kind::Comma);
		case ':':
			return atom(Lexer_Token::token_Kind::Colon);
		case ';':
			return atom(Lexer_Token::token_Kind::SemiColon);
		case '"':
			return atom(Lexer_Token::token_Kind::DoubleQuote);
		case '\'':
			return atom(Lexer_Token::token_Kind::SingleQuote);
		}
	}
}


// Identifier 
Lexer_Token Lexer::Identifier() noexcept 
{
	const char* begin = m_begin;
	
	// get char
	get();
	
	// while char is an identifier, peek and if it is, we get that shit
	while (is_Identifier_Char(peek()))
	{
		get();
	}
	return Lexer_Token(Lexer_Token::token_Kind::Identifier, begin, m_begin);
}

// Digit
Lexer_Token Lexer::Number() noexcept
{
	const char* begin = m_begin;

	// get char
	get();

	// while char is a digit, peek and if it is, we get that shit
	while (is_Digit(peek()) || is_decimal(peek())) get();
	{
		get();
	}
	return Lexer_Token(Lexer_Token::token_Kind::Number, begin, m_begin);
}

// Comment
Lexer_Token Lexer::comments() noexcept
{
	const char* begin = m_begin;
	
	// get char
	get();
	
	if (peek() == '/')
	{
		get();

		begin = m_begin;
		while (peek() != '\0')
		{
			if (get() == '\n')
			{
				return Lexer_Token(Lexer_Token::token_Kind::Comment, begin, distance(begin, m_begin) - 1);
			}
		}
		return Lexer_Token(Lexer_Token::token_Kind::UNEXPECTED, m_begin, 1);
	}
	else {
		return Lexer_Token(Lexer_Token::token_Kind::Comment, begin, 1);
	}
}

ostream& operator<<(ostream& os, const Lexer_Token::token_Kind& kind) noexcept
{
	// Declare the name for our tokens
	static const char* const token_Names[] = {
		"Identifier",
		"Number",
		"LPAREN",
		"RPAREN",
		"LSQUAREBRAC",
		"RSQUAREBRAC",
		"LCURLYBRAC",
		"RCURLYBRAC",
		"ARROW_LEFT",
		"ARROW_RIGHT",
		"EQUAL",
		"PLUS",
		"MINUS",
		"MULTIPLY",
		"Comment",
		"Comma",
		"Colon",
		"SemiColon",
		"DoubleQuote",
		"SingleQuote",
		"END",
		"UNEXPECTED"
	};
	return os << token_Names[static_cast<int>(kind)];
}


int main() {
	auto code =
		"x = 2.066721823991;\n"
		"var a = a.b()";
	
	Lexer lexer(code);
	
	for (auto token = lexer.next_Token();
		not token.is_One_Of(Lexer_Token::token_Kind::END, Lexer_Token::token_Kind::UNEXPECTED); 
		token = lexer.next_Token()) {
		cout << setw(12) << token.kind() << "|" << token.lexeme() << "|\n";
	}
}