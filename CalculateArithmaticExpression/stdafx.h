// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#ifndef _CALCULATE_ARITHMATIC_EXPRESSION_
#define _CALCULATE_ARITHMATIC_EXPRESSION_
#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <assert.h>

using namespace std;

template <typename E>
class Link {
public:
	E element;
	Link *next;
	Link(const E& elem, Link* nex = NULL) {
		element = elem;  next = nex; 
	}
	Link(Link* nex = NULL) {
		next = nex; 
	}
};

//stack 
template <typename E>
class LStack {
private:
	Link<E>* top;
	int size;

public:
	LStack() {
		top = NULL;  size = 0;
	}
	~LStack() {
		clear();
	}
	bool IsEmpty() const {
		if (size == 0)
			return true;
		return false;
	}
	void clear() {
		while (top != NULL) {
			Link<E>* temp = top;
			top = top->next;
			delete temp;
		}
		size = 0;
	}
	void push(const E& it) {
		top = new Link<E>(it, top);
		size++;
	}
	int getSize() const {
		return size;
	}
	void print() {
		while (size) {
			cout << pop() << " ";
		}
		cout << endl;
	}
	E pop() {
		assert(("stack is empty", top != NULL));
		E it = top->element;
		Link<E>* ltemp = top->next;
		delete top;
		top = ltemp;
		size--;
		return it;
	}
};

class Calculator {
private:
	LStack<double> OPND;
	LStack<char> OPTR;
	double DoOperator(double x, char op, double y);
	void DoOperator();
	bool IsOperator(char ch);
	bool IsPrior(char ch);
	bool IsDigit(char ch);
public: 
	void run();
};



#endif