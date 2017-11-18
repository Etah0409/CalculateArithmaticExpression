#include "stdafx.h"

bool Calculator::IsOperator(char ch) {
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')')
		return true;
	return false;
}

bool Calculator::IsDigit(char ch) {
	return (ch >= 48 && ch <= 57);
}

bool Calculator::IsPrior(char ch) {
	if (ch == '*' || ch == '/')
		return true;
	else if (ch == '+' || ch == '-')
		return false;
}

void Calculator::DoOperator() {
	double x, y, result;  
	char tempoperand = OPTR.pop();
	y = OPND.pop();  x = OPND.pop();
	if (tempoperand == '+' && !OPTR.IsEmpty()) {
		char temp = OPTR.pop();
		if (temp == '-') {
			tempoperand = '-';
			OPTR.push(temp);
		}
	}
	result = DoOperator(x, tempoperand, y);
	OPND.push(result);
}

double Calculator::DoOperator(double x, char ch, double y) {
	switch (ch) {
	case '+': return (x + y); break;
	case '-': return (x - y); break;
	case '*': return (x * y); break;
	case '/': return (x / y); break;
	default: break;
	}
	return 0;
}