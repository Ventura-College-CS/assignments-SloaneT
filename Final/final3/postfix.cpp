#include "Postfix.h"
#include "stack1.hpp" // include the homemade stack class
#include <iostream>
#include <string> // not entirely sure if this is necessary -- program seems to work without it

using namespace std;

Postfix::Postfix(string exp) //constructor function for Postfix class; accepts an expression, in string form, as an argument
{
    expression = exp;
}

int Postfix::isOperator(char op) // isOperator method accepts an operator in char form;
                                // returns 0 or 1 depending on whether the argument is an operator
                               // bool may also work as a return type but this ensures the program will operate on older versions of C++
{
    switch (op)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return 1; // true
	default:
		return 0; // false
	}
}

int Postfix::calculate(int op1, int op2, char opr) // accepts two operands (type int) and one operator (type char); returns an int
{
int result;
	switch (opr) // switch statement acts as a basic calculator
	{
	case '*':
		result = op1 * op2;
		break;
	case '/':
		result = op1 / op2;
		break;
	case '+':
		result = op1 + op2;
		break;
	case '-':
		result = op1 - op2;
		break;
	default:
		cout << "Undefined operator error\n";
		exit(0);
	}
	return result;
}

void Postfix::setExpression(string exp) // used to assign a new expression to an instantiated object
{
    expression = exp;
}

void Postfix::printExpression() const // getter function for the expression in question
{
    cout << expression << endl;
}

int Postfix::evaluation()
{
    int size = expression.size();
    const int N = 20;
	const int offset = 48;
    char input;
    Stack<int, N> stack;
	int opr1, opr2, result;
    for (int i = 0; i < expression.size(); i++)
	{
		input = expression[i];
		if (isdigit(input))
			stack.push(int(input) - offset);
		else if (isOperator(input))
		{
			opr1 = stack.pop();
			opr2 = stack.pop();
			result = calculate(opr1, opr2, input);
			stack.push(result);
		}
	}
	cout << "The result of the expression is " << stack.pop() << endl;
}
