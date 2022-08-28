#include "Lexer.h"


using namespace std;

static string check_String_Token;
static double check_Number_Token;
void Error() {
	// just an error code for now
	cout << "Error" << endl;
}

// Tokens for our program
enum ProgramTokens
{
	// Identifier
	token_IDENTIFIER = 0, // identifiers
	// Numbers
	token_DIGIT		 = 1, // digit
	// Math Symbols
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
	// keywords
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
	// string
	token_QUOTE		 = 33, // ""
	// Validate file
	token_SOF		 = 34, // start of file
	token_EOF		 = 35, // end of file
};

class MyClass
{
public:
	MyClass();
	~MyClass();

private:

};

MyClass::MyClass()
{
	
}

MyClass::~MyClass()
{

}

static int split_Program_To_Tokens() {
	static int last_Char = ' '; // last character read
	
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
		if (check_String_Token == "Start" || "start", __argc)
		{
			return token_SOF;
		}
		else { cout << "Can't identify the start of your Haxor Program :(" << endl; }
		
		if (check_String_Token == "End" || "end", __argc)
		{
			return token_EOF;
		}
		else { cout << "Can't identify the end of your Haxor Program :(" << endl;}
		// Check keywords
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

}