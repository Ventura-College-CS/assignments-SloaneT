#include <iostream>
#include "stack1.hpp"
#include "Postfix.h"

using namespace std;

int main()
{
    Postfix postfix_exp("243*+5+");

    postfix_exp.evaluation();

    postfix_exp.setExpression("283*+5+");

    postfix_exp.printExpression();

}




