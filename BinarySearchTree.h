#pragma once
class BNode {
public:
	BNode* lchild;
	int data;
	BNode* rchild;
};
class BinarySearchTree {
public:
	BNode* root;
	BinarySearchTree() {
		root = NULL;
	}
	void insert(int key) {
		BNode* t = root;
		BNode* r=NULL, * p;
		if (root == NULL) {//if the tree is empty
			p = new BNode;
			p->data = key;
			p->lchild = p->rchild = NULL;
			root = p;
			return;
		}
		while (t != NULL) {//check if node exists
			r = t;
			if (key < t->data) {
				t = t->lchild;
			}
			else if (key > t->data) {
				t = t->rchild;
			}
			else {
				return;//if the node exists exit
			}
		}
		p = new BNode;//insert the node
		p->data = key;
		p->lchild = p->rchild = NULL;
		if (key < r->data) {
			r->lchild = p;
		}
		else {
			r->rchild = p;
		}
	}
	void inOrder(BNode *p) {
		if (p) {
			inOrder(p->lchild);
			std::cout << p->data << "\t";
			inOrder(p->rchild);
		}
	}
	BNode* search(int key) {
		BNode* t = root;
		while (t) {
			if (key == t->data) {
				return t;
			}
			else if (key < t->data) {
				t = t->lchild;
			}
			else {
				t = t->rchild;
			}
		}
		return NULL;
	}
	BNode* deleteNode(BNode *p,int key) {
		BNode* q;
		if (p == NULL) {
			return NULL;
		}
		if (p->lchild == NULL && p->rchild == NULL) {
			if (p == root) {
				root = NULL;
			}
			delete p;
			return NULL;
		}
		if (key < p->data) {
			p->lchild = deleteNode(p->lchild,key);
		}
		else if (key > p->data) {
			p->rchild = deleteNode(p->rchild, key);
		}
		else {//choosepredecessor or successor based on height
			if (height(p->lchild) > height(p->rchild)) {
				q=inOrderPred(p->lchild);
				p->data = q->data;
				p->lchild = deleteNode(p->lchild, q->data);
			}
			else {
				q = inOrderSucc(p->rchild);
				p->data = q->data;
				p->rchild = deleteNode(p->rchild, q->data);
			}
		}
		return p;
	}
	BNode* inOrderSucc(BNode* p) {
		while (p && p->lchild != NULL) {
			p = p->lchild;
		}
		return p;
	}
	BNode* inOrderPred(BNode* p) {
		while (p && p->rchild != NULL) {
			p = p->rchild;
		}
		return p;
	}
	int height(BNode* p) {
		if (p == NULL) {
			return 0;
		}
		int x, y;
		x = height(p->lchild);
		y = height(p->rchild);
		return x > y ? x + 1 : y + 1;
	}
};
