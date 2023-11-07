#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
    string infixExpression;
    cout << "Please enter an infix expression: ";
    cin >> infixExpression;

    if (isBalanced(infixExpression))
    {
        string postfixExpression = infixToPostfix(infixExpression);
        cout << "The Postfix expression is: " << postfixExpression << endl;
    }
    else
    {
        cout << "Invalid expression. Unbalanced parentheses in infix expression." << endl;
    }

    return 0;
}