#ifndef AST_H
#define AST_H

#include "../Lexer/Lexer.h"
#include "../CodeGen/CodeGen.h"

using namespace std;

// Base class for all expressions
class Expression {
public:
	virtual ~Expression() {}
	//virtual Value *codegen() = 0;
};

// DecimalExpression, Derived class - Expression class for numeric literals like "1.0"
class decimal_Number_Expression : public Expression {
	double decimal_Value;
	
public:
		decimal_Number_Expression(double decimal_Value) : decimal_Value(decimal_Value) {}
		//Value* codegen() override;
};


// IntegerExpression - Expression class for integer literals like "1"
class integer_Number_Expression : public Expression  {
	int int_Value;
public:
	integer_Number_Expression(int int_Value) : int_Value(int_Value) {}
};

// VariableExpression - Expression class for variables like "x"
class VariableExpression : public Expression {
	string Name;
public:
	VariableExpression(const string &Name) : Name(Name) {}
};

// BinaryExpression - Expression class for binary operators like "+"
class BinaryExpression : public Expression {
	char op;
	unique_ptr<Expression> LHS, RHS;

public:
	BinaryExpression(char op, unique_ptr<Expression> LHS, unique_ptr<Expression> RHS) : op(op), LHS(move(LHS)), RHS(move(RHS)) {}
};

// CallExpression - Expression class for function calls
class CallExpression : public Expression {
	string Callee;
	vector<unique_ptr<Expression>> Args;
public:
	CallExpression(const string &Callee, vector<unique_ptr<Expression>> Args) : Callee(Callee), Args(move(Args)) {}
};

// Prototype - This class represents the "prototype" for a function, which captures its name, and its arguments
class Prototype {
	string Name;
	vector<string> Args;
public:
	Prototype(const string& Name, const vector<string> &Args) : Name(Name), Args(Args) {}
	
	const string& getName() const { return Name; }
};

// FunctionDefinition - This class represents a function definition itself.
class FunctionDefinition {
	unique_ptr<Prototype> Proto;
	unique_ptr<Expression> Body;
	
public:
	FunctionDefinition(unique_ptr<Prototype> Proto, unique_ptr<Expression> Body) : Proto(move(Proto)), Body(move(Body)) {}
};

#endif