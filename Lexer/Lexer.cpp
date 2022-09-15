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
	{'+', token_PLUS},
	{'-', token_MINUS},
	{'*', token_TIMES},
	{'/', token_DIVIDE},
	{'(', token_LPARENTHE},
	{')', token_RPARENTHE},
	{'[', token_LBRACKET},
	{']', token_RBRACKET},
	{'{', token_LCURLYBRAC},
	{'}', token_RCURLYBRAC},
	{'=', token_EQUAL},
	{',', token_COMMA},
	{':', token_COLON},
	{';', token_SEMICOLON},
	{'<', token_LTH},
	{'>', token_RTH},
	{'!', token_NOT},
	{'&', token_AND},
	{'|', token_OR},
};

// Map keywords
map<string, int> keyword_Map = {
	{"if", token_IF},
	{"else", token_ELSE},
	{"while", token_WHILE},
	{"return", token_RETURN},
	{"int", token_INT},
	{"float", token_FLOAT},
	{"true", token_TRUE},
	{"false", token_FALSE},
	{"struct", token_STRUCT},
	{"start", token_SOF},
	{"end", token_EOF},
};




int split_Program_To_Tokens() {
	int last_Char = ' '; // last character read

	// Skip any whitespace
	while (isspace(last_Char)) {
		last_Char = getchar();
	}
	

	if (isalpha(last_Char)) {
		// identifier or keyword
		// read until non-alphabetic character
		check_String_Token = last_Char;
		while (isalnum(last_Char = getchar())) {
			check_String_Token += last_Char;
		}

		// Check if it is a math symbol
		if (check_String_Token == "+") {
			return token_PLUS;
		}
		else if (check_String_Token == "-") {
			return token_MINUS;
		}
		else if (check_String_Token == "*") {
			return token_TIMES;
		}
		else if (check_String_Token == "/") {
			return token_DIVIDE;
		}
		else if (check_String_Token == "=") {
			return token_EQUAL;
		}
		else if (check_String_Token == ",") {
			return token_COMMA;
		}
		else if (check_String_Token == ":") {
			return token_COLON;
		}
		else if (check_String_Token == ";") {
			return token_SEMICOLON;
		}
		else if (check_String_Token == "(") {
			return token_LPARENTHE;
		}
		else if (check_String_Token == ")") {
			return token_RPARENTHE;
		}
		else if (check_String_Token == "[") {
			return token_LBRACKET;
		}
		else if (check_String_Token == "]") {
			return token_RBRACKET;
		}
		else if (check_String_Token == "{") {
			return token_LCURLYBRAC;
		}
		else if (check_String_Token == "}") {
			return token_RCURLYBRAC;
		}
		else if (check_String_Token == "=>") {
			return token_ARROW;
		}
		else if (check_String_Token == "==") {
			return token_DEQ;
		}
		else if (check_String_Token == "<") {
			return token_LTH;
		}
		else if (check_String_Token == ">") {
			return token_RTH;
		}
		else if (check_String_Token == "&&") {
			return token_AND;
		}
		else if (check_String_Token == "||") {
			return token_OR;
		}
		else if (check_String_Token == "!") {
			return token_NOT;
		}
		else { EXIT_FAILURE; }

		// Check if it is a keyword
		if (check_String_Token == "if")
		{
			return token_IF;
		}
		else if (check_String_Token == "else")
		{
			return token_ELSE;
		}
		else if (check_String_Token == "int") {
			return token_INT;
		}
		else if (check_String_Token == "true") {
			return token_TRUE;
		}
		else if (check_String_Token == "false")
		{
			return token_FALSE;
		}
		else if (check_String_Token == "enum") {
			return token_ENUM;
		}
		else if (check_String_Token == "function") {
			return token_FUNCTION;
		}
		else if (check_String_Token == "define") {
			return token_DEFINE;
		}
		else if (check_String_Token == "using") {
			return token_USING;
		}
		else { cout << "Error in Lexer, but i gotta write a better function for error handling" << endl; }

		// Check if it is a digit
		if (isdigit(last_Char)) {
			// read until non-digit character
			check_String_Token = last_Char;
			while (isdigit(last_Char = getchar())) {
				check_String_Token += last_Char;
			}
			return token_DIGIT;
		}
		else { cout << "Error in Lexer" << endl; }

		// Handle comments
		if (last_Char == '//') {
			do
				last_Char = getchar();
			while (last_Char != EOF && last_Char != '\n' && last_Char != '\r'); // read until newline

			if (last_Char != EOF)
				return split_Program_To_Tokens(); // read next token
		}

		// Check for end of file. Don't eat the EOF.
		if (last_Char == EOF)
			return token_EOF;

		// Otherwise, just return the character as its ascii value
		return last_Char;
	}
	
}