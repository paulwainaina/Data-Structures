#pragma once
class LinkedList {
	struct Node {
		int data;
		Node* next;
	}*first = NULL, * t, * last;
public:
	LinkedList(int data) {
		first = (Node*)malloc(sizeof(Node));
		first->data = data;
		first->next = NULL;
		last = first;
	}
	void addNode(int data) {
		t = (Node*)malloc(sizeof(Node));
		t->data = data;
		t->next = NULL;
		last->next = t;
		last = t;
	}
	int nodeCount() {
		int c = 0;
		Node* p = first;
		while (p != NULL) {
			c++;
			p = p->next;
		}
		return c;
	}
	int sumList() {
		int sum = 0;
		Node* p = first;
		while (p != NULL) {
			sum = sum + p->data;
			p = p->next;
		}
		return sum;
	}
	void insertNode(int x, int position) {//the node count starts from 1 and not 0
		if (position == 1) {
			Node* t = new Node;
			t->data = x;
			t->next = first;
			first = t;
		}
		else if (position > 1 && position < nodeCount()) {
			Node* t = new Node;
			t->data = x;
			Node* p = first;
			for (int i = 0;i < position - 1;i++) {
				p = p->next;
			}
			t->next = p->next;
			p->next = t;
		}
		else {
			std::cout << "Position out of range" << std::endl;
		}
	}
	int deleteNode(int position) {
		int x = 0;
		if (position == 1) {
			Node* p = first;
			x = first->data;
			first = first->next;
			delete p;
			return x;
		}
		else if (position > 1 && position < nodeCount()) {
			Node* p = first;
			Node* q = NULL;
			for (int i = 0;i < position - 1;i++) {
				q = p;
				p = p->next;
			}
			q->next = p->next;
			x = p->data;
			delete p;
			return x;
		}
		else {
			std::cout << "Position out of range" << std::endl;
		}
		return x;
	}
	int maxNode() {
		int m = INT_MIN;
		Node* p = first;
		while (p != NULL) {
			if (p->data > m) {
				m = p->data;
			}
			p = p->next;
		}
		return m;
	}
	bool isSorted() {
		int x = INT_MIN;
		Node* p = first;
		while (p != NULL) {
			if (p->data < x) {
				return false;
			}
			x = p->data;
			p = p->next;
		}
		return true;
	}
	Node* search(int key) {
		Node* p = first;
		Node* q = NULL;
		while (p != NULL) {
			if (p->data == key) {//improved search
				q->next = p->next;
				p->next = first;
				first = p;
				return p;
			}
			q = p;
			p = p->next;
		}
		return NULL;
	}
	void displayList() {
		Node* p = first;
		while (p != NULL) {
			std::cout << p->data << "\t";
			p = p->next;
		}
		std::cout << std::endl;
	}
	void reverse() {//sliding pointers
		Node* p = first;
		Node* q = NULL;
		Node* r = NULL;
		while (p != NULL) {
			r = q;
			q = p;
			p = p->next;
			q->next = r;
		}
		first = q;
	}
};