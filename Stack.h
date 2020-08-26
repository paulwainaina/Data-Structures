#pragma once
//Application paranthesis matching
class Node {
public:
	char data;
	Node* next;
};
class Stack {
	Node* top;
public:
	Stack() {
		top = NULL;
	}
	void push(char x) {
		Node* t = new Node;
		if (t == NULL) {
			std::cout << "stack is full" << std::endl;
		}
		else {
			t->data = x;
			t->next = top;
			top = t;
		}
	}
	bool isempty() {
		if (top == NULL) {
			return true;
		}
		return false;
	}
	int pop() {
		char x = '\0';
		if (isempty()) {
			std::cout << "stack is empty" << std::endl;
		}
		else {
			x = top->data;
			Node* t = top;
			top = top->next;
			delete t;
		}
		return x;
	}
	void display() {
		Node* p = top;
		while (p != NULL) {
			std::cout << p->data << "\t" << std::endl;
			p = p->next;
		}
		std::cout << std::endl;
	}
	bool expressonMatches(char* exp) {
		int i;
		for (i = 0;exp[i] != '\0';i++) {
			if (exp[i] == '(') {
				push(exp[i]);
			}
			else if (exp[i] == ')') {
				if (top == NULL) {
					return false;
				}
				pop();
			}
		}
		if (top == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
};
