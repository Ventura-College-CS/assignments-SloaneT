#ifndef POSTFIX_H
#define POSTFIX_H

#include <iostream>
#include <string>
using namespace std;

class Postfix
{
private:
	string expression;
	int isOperator(char);
	int calculate(int, int, char);

public:
	Postfix();
	Postfix(string);
	void setExpression(string exp);
	void printExpression() const;
	int evaluation();
};

#endif
