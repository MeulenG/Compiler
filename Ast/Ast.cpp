#include "Ast.h"

using namespace std;

class Expression {

public:
	virtual ~Expression() {}

private:

};

// DecimalExpression - Expression class for numeric literals like "1.0"
class decimal_Number_Expression : public Expression {
	double value;
public:
	decimal_Number_Expression(double decimal_Value) : decimal_Value(decimal_Value) {}
};

// IntegerExpression - Expression class for integer literals like "1"
class integer_Number_Expression : public Expression {
	int value;
public:
	integer_Number_Expression(int int_Value) : int_Value(int_Value) {}
};

// VariableExpression - Expression class for variables like "x"
class VariableExpression : public Expression {
	string Name;
public:
	VariableExpression(const string& Name) : Name(Name) {}
};

// BinaryExpression - Expression class for binary operators like "+"
class BinaryExpression : public Expression {
	Expression* Left;
	Expression* Right;
	char Op;
public:
	BinaryExpression(Expression* Left, char Op, Expression* Right) : Left(Left), Right(Right), Op(Op) {}
};

// CallExpression - Expression class for function calls
class CallExpression : public Expression {
	string Callee;
	vector<Expression*> Args;
public:
	CallExpression(const string& Callee, const vector<Expression*>& Args) : Callee(Callee), Args(Args) {}
};

// Prototype - This class represents the "prototype" for a function, which captures its name, and its arguments
class Prototype {
	string Name;
	vector<string> Args;
public:
	Prototype(const string& Name, const vector<string>& Args) : Name(Name), Args(Args) {}
};


// FunctionDefinition - This class represents a function definition itself.
class FunctionDefinition {
	Prototype* Proto;
	vector<Expression*> Body;
public:
	FunctionDefinition(Prototype* Proto, const vector<Expression*>& Body) : Proto(Proto), Body(Body) {}
};