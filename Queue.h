#pragma once

//Application is priority queue is operating systems
class QNode {
public:
	int data;
	QNode* next;
};
class Queue {
	QNode* front, * rear;
public:
	Queue() {
		front = rear = NULL;
	}
	void enqueue(int x) {
		QNode* t = new QNode;
		if (t == NULL) {
			std::cout << "queue is full" << std::endl;
		}
		else {
			t->data = x;
			t->next = NULL;
			if (front == NULL) {
				front = rear = t;
			}
			else {
				rear->next = t;
				rear = t;
			}
		}
	}
	int dequeue() {
		int x = -1;
		QNode* t;
		if (front == NULL) {
			std::cout << "queue is empty" << std::endl;
		}
		else {
			x = front->data;
			t = front;
			front = front->next;
			delete t;
		}
		return x;
	}
	void display() {
		QNode* p = front;
		while (p != NULL) {
			std::cout << p->data << "\t";
			p = p->next;
		}
		std::cout << std::endl;
	}
};
