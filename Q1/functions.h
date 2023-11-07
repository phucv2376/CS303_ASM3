#pragma once
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c);
int precedence(char op);
bool isBalanced(const string expression);
string infixToPostfix(const string infix);
