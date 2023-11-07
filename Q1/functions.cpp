#include "functions.h"

using namespace std;

bool isOpen(char c)
{
    const string OPEN = "([{";
    return OPEN.find(c) != string::npos;
}

bool isClose(char c)
{
    const string CLOSE = ")]}";
    return CLOSE.find(c) != string::npos;
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

/**
 * Identify precendence of operator according to PEMDAS.
 * @params {char} op - operator from an expression.
 * @returns priority of operator (2 takes higher precedence than 1).
 */
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    return 0;
}

/**
 * Checks if expression is balanced
 * @params {string} expression - given expression to check.
 * @returns Whether the expression is balanced
 */
bool isBalanced(const string expression)
{
    stack<char> s; // Stack to keep track of {[( in an expression
    for (char c : expression)
    {
        if (isOpen(c)) // Add to stack if open
        {
            s.push(c);
        }
        else if (isClose(c))
        {
            if (s.empty())
                return false; // Unbalanced parentheses
            char top = s.top();
            if ((c == ')' && top == '(') || (c == '}' && top == '{') || (c == ']' && top == '['))
                s.pop();
            else
                return false; // Mismatched parentheses
        }
    }
    return s.empty();
}

/**
 * Converts an infix expression into a postfix expression
 * @params {string} infix - a given infix expression
 * @returns postfix version of a given infix expression
 */
string infixToPostfix(const string infix)
{
    vector<string> postfix;
    string operand = "";
    stack<char> operators;
    if (!isBalanced(infix)) // Check if expression is balanced
        throw runtime_error("Invalid Expression. The parentheses in the user entered experession are not balanced");

    for (char c : infix)
    {
        if (isalnum(c)) // If number or letter
        {
            string s(1, c);
            operand.append(s);
        }
        else if (isOpen(c)) // If an open parrenthesis
        {
            operators.push(c);
        }
        else if (isClose(c)) // If a close parenthesis
        {
            while (!isOpen(operators.top()))
            {
                // Add operand to the postfix before adding operator
                postfix.push_back(operand);
                operand = "";

                // Add operator
                string s(1, operators.top());
                postfix.push_back(s);
                operators.pop();
            }
            operators.pop();
        }
        else
        {
            while (!operators.empty() && precedence(c) <= precedence(operators.top())) // Handle precedence of operators
            {
                // Add operand to the postfix before adding operator
                postfix.push_back(operand);
                operand = "";

                // Add operator
                string s(1, operators.top());
                postfix.push_back(s);
                operators.pop();
            }

            // Add the remaining operand to prefix
            postfix.push_back(operand);
            operand = "";

            operators.push(c);
        }
    }

    while (!operators.empty())
    {
        // Add the remaining operand to prefix
        postfix.push_back(operand);

        // Add the remaining operator to prefix
        string s(1, operators.top());
        postfix.push_back(s);
        operators.pop();
    }

    // Covert postfix from vector to str.
    string postfix_str = "";
    for (string s : postfix)
    {
        postfix_str.append(s);
        postfix_str.append(" ");
    }
    return postfix_str;
}
