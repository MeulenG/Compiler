#include "Parser.h"
#include "../Ast/Ast.h"

using namespace std;

// Curtok/getNextToken. Curtok is the current token the parser is looking at. getNextToken reads another token from the Lexer and updates Curtok.
int current_token;
int getNextToken() {
	current_token = getNextToken();
	return current_token;
}

// Precedence for binary operators.
map<char, int> op_Precedence = {
	{'=', 1},
	{'<', 2},
	{'>', 2},
	{'+', 3},
	{'-', 3},
	{'*', 4},
	{'/', 4}
};

// Function to determine the precedence of the current token.
int getPrecedence() {
	if (!op_Precedence.count(current_token)) {
		return -1;
	}
	return op_Precedence[current_token];
}

// LogError* - These functions are used to report errors to the user.
unique_ptr<Expression> LogError(const char* str) {
	fprintf(stderr, "Error: %s\n", str);
	return nullptr;
}

