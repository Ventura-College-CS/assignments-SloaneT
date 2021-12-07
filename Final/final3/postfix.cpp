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

int Postfix::evaluation() // evaluates a postfix expression
{
    int size = expression.size(); // a size variable (type int) is declared, assigned to the length of the expression in bytes
    const int N = 20; // N will be entered as an argument for the size of a Stack object
	const int offset = 48; // expression will be evaluated as characters, not int, which have ASCII values starting at 48.  0 = ASCII 48, etc.
    char input;
    Stack<int, N> stack; // creates a Stack object of minimum size N
	int opr1, opr2, result;
    for (int i = 0; i < expression.size(); i++) // from 0 until the end of the expression, based on its length in bytes
	{
		input = expression[i]; // each given index of the expression is a char
		if (isdigit(input)) // if the input is an operand (using Stack method)...
			stack.push(int(input) - offset); // push the input, subtracting 48 to account for ASCII value, to the top of the stack...
		else if (isOperator(input)) // otherwise, if the input is an operator (using Stack method)
		{
			opr1 = stack.pop(); // remove the first operand from top of stack
			opr2 = stack.pop(); // remove the second operand from top of stack
			result = calculate(opr1, opr2, input);  // use Postfix method to calculate, using the top two operands along with the given operator
			stack.push(result); // the current result is pushed to the stack.  This does not mean the calculation is finished.
		}
	}
	cout << "The result of the expression is " << stack.pop() << endl; // once the for loop has finished, the final result is at the top of the stack, and can be popped
}
