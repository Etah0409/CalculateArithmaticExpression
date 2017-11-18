#include "stdafx.h"

void Calculator::run() {
	cout << "input your arithmatic expression:";
	OPND.clear();  OPTR.clear();
	char ch;  double operand;
	ch = getchar();
	while (ch != '\n') {  //this while is used to operate * , / and ()
		if (IsDigit(ch) || ch == '.') {
			cin.putback(ch);
			cin >> operand;
			OPND.push(operand);
		}
		else if (IsOperator(ch)) {
			if (ch == '(' || !IsPrior(ch))
				OPTR.push(ch);
			else if (ch == ')') {
				char tempoperand;
				tempoperand = OPTR.pop();
				while (tempoperand != '(') {
					if (OPTR.IsEmpty()) {
						cout << "input error: no proper brackets!";
						break;
					}
					OPTR.push(tempoperand);
					DoOperator();
					tempoperand = OPTR.pop();
				}
				if (!OPTR.IsEmpty())
					tempoperand = OPTR.pop();
				while (IsPrior(tempoperand)) {
					OPTR.push(tempoperand);
					DoOperator();
					if (OPTR.IsEmpty())		
						break;
					tempoperand = OPTR.pop();
				}
				if (!IsPrior(tempoperand))
					OPTR.push(tempoperand);
			}
			else if (IsPrior(ch)) {  //ch = */;
				char tempch = ch;
				ch = getchar();
				if (ch != '(' && ch != ')') {
					double temp, result;
					cin.putback(ch);
					cin >> temp;
					operand = OPND.pop();
					result = DoOperator(operand, tempch, temp);
					OPND.push(result);
				}
				else {
					OPTR.push(tempch);
					cin.putback(ch);
				}
			}
		}
		ch = getchar();
	}
	while (!OPTR.IsEmpty()) {  //operate the + and -
		DoOperator();
	}
	if (OPND.getSize() != 1)
		cout << "input error!" << endl;
	else
		cout << "The result is " << OPND.pop() << endl;
	system("pause");
}