#include "Parser.h"
#include "../Ast/Ast.h"
#include "../Lexer/Lexer.h"
#include "../Ast/Ast.h"
#include "../CodeGen/CodeGen.h"

using namespace std;

// Instanciate the lexer
Lexer lexer;

// Curtok/getNextToken. Curtok is the current token the parser is looking at. getNextToken reads another token from the Lexer and updates Curtok.
int current_token;
int getNextToken() {
	return current_token = lexer.split_Program_To_Tokens();
}

// Map Precedence for binary operators.
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
	// Make an instance of ParseExpression
	unique_ptr<Expression> ParseExpression();
	// Eat '('
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

// Primary
unique_ptr<Expression> ParsePrimary() {
	switch (current_token)
	{
	case '(':
		return ParseParentExpre();
	case token_IDENTIFIER:
		return ParseIdentifierExpre();
	case token_NUM_LITERAL:
		return ParseLiteralNumExpre();
	case token_INT:
		return ParseIntegersExpre();
	default:
		cout << "Expected a    :    '(', identifier, number, number_Int    " << endl;
		return nullptr;
	}
}

// Parse Binary Operators
unique_ptr<Expression> ParseBinaryOpRHS(int expr_Precedence, unique_ptr<Expression> LHS) {
	// If this is a binop, find its precedence.
	while (true)
	{
		int token_Precedence = getPrecedence(); // Get the precedence of the current token
		// if this tokens binary operator binds atleast as tightly as the current binary operator, then we consume, otherwise we dont
		if (token_Precedence < expr_Precedence)
		{
			return LHS; // return the left hand side
		}
		// Okay, we know this is a binop.
		int binOp = current_token;
		getNextToken(); // Eat binop

		// Parse the primary expression after the binary operator.
		auto rhs = ParsePrimary();
		if (!rhs)
		{
			return nullptr;
		}

		// If BinOp binds less tightly with RHS than the operator after RHS, let the pending operator take RHS as its LHS.
		// Same method as above just for the right-hand-side
		int next_Precedence = getPrecedence();
		if (token_Precedence < next_Precedence)
		{
			rhs = ParseBinaryOpRHS(token_Precedence + 1, move(rhs));
			if (!rhs)
			{
				return nullptr;
			}
		}

		// return the binary expression
		LHS = make_unique<BinaryExpression>(binOp, move(LHS), move(rhs));
	}
}

// Parse Expression lhs
unique_ptr<Expression> ParseExpression() {
	auto lhs = ParsePrimary();
	
	if (!lhs)
	{
		return nullptr;
	}
	return ParseBinaryOpRHS(0, move(lhs));
}

// Parse Prototype
unique_ptr<Prototype> ParsePrototype() {
	// Initialize variables
	const string identifier_Name = check_String_Token;
	getNextToken(); // Eat Identifier

	if (current_token != '(')
	{
		cout << "Expected a    :    '('    " << endl;
		return nullptr;
	}
	vector<string> arg_Names;
	while (getNextToken() == token_IDENTIFIER)
	{
		arg_Names.push_back(check_String_Token);
	}
	if (current_token != ')')
	{
		cout << "Expected a    :    ')'    " << endl;
		return nullptr;
	}
	getNextToken(); // Eat ')'
	return make_unique<Prototype>(identifier_Name, move(arg_Names));
}

// Parse Function
unique_ptr<FunctionDefinition> ParseFunction() {
	getNextToken(); // Eat 'begin'
	getNextToken(); // Eat 'function'
	auto proto = ParsePrototype();
	if (!proto)
	{
		return nullptr;
	}
	if (auto body = ParseExpression())
	{
		return make_unique<FunctionDefinition>(move(proto), move(body));
	}
	return nullptr;
}

///////////////////////////////////
// Parse Top Level Expression
///////////////////////////////////
