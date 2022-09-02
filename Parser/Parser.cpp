#include "Parser.h"
#include "../Ast/Ast.h"
#include "../Lexer/Lexer.h"


using namespace std;

// Instanciate the lexer
Lexer lexer;



// Curtok/getNextToken. Curtok is the current token the parser is looking at. getNextToken reads another token from the Lexer and updates Curtok.
int current_token;
int getNextToken() {
	return current_token = lexer.split_Program_To_Tokens();
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


// Parse Numeric Literals like "1.0"
unique_ptr<Expression> ParseLiteralNumExpre() {
	double num_Literal;
	num_Literal = check_Number_Token; // get the number literal from the Lexer
	auto result = make_unique<decimal_Number_Expression>(num_Literal);
	getNextToken();
	return move(result);
}

// Parse Integers like "1"
unique_ptr<Expression> ParseIntegersExpre() {
	int num_Int;
	num_Int = check_Number_Token_Int; // get the integer number from the Lexer
	auto result = make_unique<decimal_Number_Expression>(num_Int);
	getNextToken();
	return move(result);
}

// parenexpr := '(' expression ')'
unique_ptr<Expression> ParseParentExpre() {
	unique_ptr<Expression> ParseExpression();
	getNextToken();
	auto V = ParseExpression();
	if (!V)
	{
		return nullptr;
	}
	if (current_token != ')')
	{
		cout << "Expected a    :    ')'    " << endl;
	}
	getNextToken();
	return V;
}

// identifier-expression
unique_ptr<Expression> ParseIdentifierExpre() {
	// Initialize variables
	const string identifier_Name = check_String_Token;
	unique_ptr<Expression> ParseExpression();

	getNextToken(); // Eat Identifier

	if (current_token != '(')
	{
		return make_unique<VariableExpression>(identifier_Name);
	}
	
	// call
	getNextToken(); // Eat (
	vector<unique_ptr<Expression>> args;
	if (current_token != ')')
	{
		while (true)
		{
			auto arg = ParseExpression();
			if (!arg)
			{
				return nullptr;
			}
			args.push_back(move(arg));
			if (current_token == ')')
			{
				break;
			}
			if (current_token != ',')
			{
				cout << "Expected a    :    ','    " << endl;
			}
			getNextToken();
		}
	}
	getNextToken(); // Eat )
	
	return make_unique<CallExpression>(identifier_Name, move(args));
}

// 