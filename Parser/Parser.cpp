#include "Parser.h"
#include "../Ast/Ast.h"
#include "../Lexer/Lexer.h"
#include "../Ast/Ast.h"
#include "../CodeGen/CodeGen.h"

using namespace std;

Lexer lex;

// Gets the next token
Token Parser::get_Next_Token() noexcept 
{
	peek();
	get();
}
// Holds our current token
Token Parser::current_Token() noexcept 
{
	lex.next();
}

// Map Precedence for binary operators.
std::map<int, Token::Kind> op_Precedence = 
{
	{1, Token::Kind::Equal},
	{2, Token::Kind::LessThan},
	{2, Token::Kind::GreaterThan},
	{3, Token::Kind::Plus},
	{3, Token::Kind::Minus},
	{4, Token::Kind::Asterisk},
	{4, Token::Kind::Slash}
//	{'=', 1},
//	{'<', 2},
//	{'>', 2},
//	{'+', 3},
//	{'-', 3},
//	{'*', 4},
//	{'/', 4}
};

Token Parser::install_BinOP_Precedence() noexcept 
{
	if (op_Precedence > op_Precedence.count(get_Next_Token()))
	{

	}
}


// Function to determine the precedence of the current token.
Token Parser::get_Precedence() noexcept
{
	// If current tokens precedence is greater than the next operators token, we keep
	if (op_Precedence.count(current_Token()) > op_Precedence.count(get_Next_Token()))
	{
		return current_Token();
	}
	// Else fuck our current token, we take the next
	return get_Next_Token();
}


// Parse Numeric Literals like "1.0"
unique_ptr<Expression> ParseLiteralNumExpre()
{
	double num_Literal;
	num_Literal = static_cast<int>(Token::Kind::Number);
	if (Lexer::token_List.contains(num_Literal) != Lexer::token_List.end())
	{
		return -1;
	}
	auto result = make_unique<decimal_Number_Expression>(num_Literal);
	getNextToken();
	return move(result);
}

// Parse Integers like "1"
unique_ptr<Expression> ParseIntegersExpre() 
{
	int num_Int;
	num_Int = static_cast<int>(Token::Kind::Number);
	if (Lexer::token_List.find(num_Int) != Lexer::token_List.end())
	{
		return -1;
	}
	auto result = make_unique<decimal_Number_Expression>(num_Int);
	getNextToken();
	return move(result);
}

// parenexpr := '(' expression ')'
unique_ptr<Expression> ParseParentExpre() 
{
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
unique_ptr<Expression> ParseIdentifierExpre() 
{
	// Initialize variables
	const string identifier_Name = lex.next();
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
unique_ptr<Expression> ParsePrimary() 
{
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
unique_ptr<Expression> ParseBinaryOpRHS(int expr_Precedence, unique_ptr<Expression> LHS) 
{
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
unique_ptr<Expression> ParseExpression() 
{
	auto lhs = ParsePrimary();
	
	if (!lhs)
	{
		return nullptr;
	}
	return ParseBinaryOpRHS(0, move(lhs));
}

// Parse Prototype
unique_ptr<Prototype> ParsePrototype() 
{
	// Initialize variables
	const string identifier_Name = Lexer::next();
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
unique_ptr<FunctionDefinition> ParseFunction() 
{
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
