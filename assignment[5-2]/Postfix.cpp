#include "Postfix.h"
#include "stack1.hpp"
#include <iostream>
#include <string>

using namespace std;

Postfix::Postfix(string exp)
{
    expression = exp;
}

int Postfix::isOperator(char op)
{
    switch (op)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return 1;
	default:
		return 0;
	}
}

int Postfix::calculate(int op1, int op2, char opr)
{
int result;
	switch (opr)
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

void Postfix::setExpression(string exp)
{
    expression = exp;
}

void Postfix::printExpression() const
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
