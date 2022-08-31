#include "Lexer.h"


using namespace std;

string check_String_Token;
double check_Number_Token;

void Error() {
	// just an error code for now
	cout << "Error" << endl;
}

int split_Program_To_Tokens(bool filename) {
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
		// Validate file
		if (check_String_Token == "start", filename)
		{
			return token_SOF, filename;
		}
		else { cout << "Can't identify the start of your Haxor Program :(" << endl; }

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
				return split_Program_To_Tokens(filename); // read next token
		}

		// Check for end of file. Don't eat the EOF.
		if (last_Char == EOF)
			return token_EOF;

		// Otherwise, just return the character as its ascii value
		return last_Char;
	}
}