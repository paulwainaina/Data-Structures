#include <iostream>

class Recursion {
	/*Application of Recusion => Tower of Hanoi, Fibonacci series, Taylor series, Combination formula*/
public:
	Recursion() {
	}
	void display(int x, bool ascending = true, int interval = 1) {//Defaults to ascending with an interval of one
		if (x > 0) {
			if (ascending) {//Prints on return.
				display(x - interval, ascending,interval);//Head recusion - function call is first to be called.
				std::cout << x << "\t";
			}
			else {//Prints before recursion function call.
				std::cout << x << "\t";
				display(x - interval, ascending,interval);//Tail recursion - the last statement is function calling itself.Time O(n) Space O(n)
			}
		}
	}
	int combination(int n, int r) {
		int num, den;
		num = factorial(n);
		den = factorial(r) * factorial(n - r);
		return num / den;
	}
	int factorial( int n) {
		if (n == 0) {
			return 1;
		}
		return factorial(n - 1) * n;
	}
	int power(int m, int n) {
		if (n == 0) {
			return 1;
		}
		return power(m, n - 1) * m;
	}
	void towerOfHanoi(int n, int A, int B, int C) {
		if (n > 0) {
			towerOfHanoi(n - 1, A, C, B);
			towerOfHanoi(n - 1, B, A, C);
		}
	}
	double taylorSeries(int x, int n) {
		double s;
		if (n == 0) {
			return s;
		}
		s = 1 + x * s / n;
		return taylorSeries(x, n - 1);
	}
};

template<class T>
class Array {
public:
	T* A;
	int length,size;
	Array(int s) {
		size= s;
		A = (T*)malloc(size * sizeof(T));
		length = 0;
	}
	~Array() {
		free(A);
	}
	void addElement( T t) {
		if (length<size) {
			A[length] = t;
			length++;
		}
		else {
			std::cout << "Array is Full : Array size: "<< size << std::endl;
		}
	}
	void insertElement(int index, T t) {
		if (length < size && index<size && index>=0) {
			for (int i = length;i > index;i--) {
				A[i] = A[i - 1];
			}
			A[index] = t;
			length++;
		}
		else if (length == size) {
			std::cout << "Array is Full : Array size: " << size << std::endl;
		}
		else {
			std::cout << "Index out of range: Array size: " << size << std::endl;
		}
	}
	T get(int index) {
		if (index >= 0 && index < length) {
			return A[index];
		}
		return -1;
	}
	void set(int index, T t) {
		if (index >= 0 && index < length) {
			 A[index]=t;
		}
	}
	T max() {
		T max = A[0];
		for (int i = 0;i < length;i++) {
			if (A[i] > max) {
				max = A[i];
			}
		}
		return max;
	}
	T min() {
		T min = A[0];
		for (int i = 0;i < length;i++) {
			if (A[i] < min) {
				min = A[i];
			}
		}
		return min;
	}
	T sum() {
		T total=0;
		for (int i = 0;i < length;i++) {
			total += A[i];
		}
		return total;
	}
	float average() {
		return sum() / length;
	}
	void deleteElement(int index) {
		if (index >= 0 && index <= length - 1) {
			for (int i = index;i < length - 1;i++) {
				A[i] = A[i + 1];
			}
			length--;
		}
		else {
			std::cout << "Index out of range: Array length: " << length-1 << std::endl;
		}
	}
	int linearSearchElement(T t) {
		for (int i = 0;i < length;i++) {
			if (t == A[i]) {
				swap(&A[i], &A[(i - 1)]);//improve the search by transposition => the more it is searched the more it moves closer to the first index.
				return i-1;
			}
		}
		return -1;
	}
	int binarySearchElement( T t) {//works only if elements are sorted
		int low=0,high=length-1,mid;
		while (low <= high) {
			mid = (low + high) / 2;
			if (t == A[mid]) {
				return mid;
			}
			else if(t == A[low]) {
				return low;
			}
			else if (t == A[high]) {
				return high;
			}
			else if (t < A[mid]) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		return -1;
	}
	void swap(T *x,T*y) {
		T temp;
		temp = *x;
		*x = *y;
		*y = temp;
	}
	void displayArray() {
		for (int i = 0;i < length;i++) {
			std::cout <<A[i]<< "\t";
		}
		std::cout << std::endl;
	}
	void reverseArray() {
		int i, j;
		for (i=0,j = length-1;i <j;i++, j--) {
			swap(&A[i], &A[j]);
		}
	}
	bool isSorted() {
		int x;
		for (x = 0;x < length ;x++); {
			if (A[x] > A[x + 1]) {
				return false;
			}
		}		
		return true;
	}
	void insertSortedElement(T t) {
		if (length != size) {
			int i = length - 1;
			while (A[i] > t) {
				A[i + 1] = A[i];
				i--;
			}
			A[i + 1] = t;
			length++;
		}
		else{
		std::cout << "Array is Full : Array size: " << size << std::endl;
		}
	}
	void rearrangePositiveNegative() {
		int i=0, j=length-1;
		while (i < j) {
			while (A[i] < 0)i++;
			while (A[i] >= 0)j--;
			if (i < j)swap(&A[i], &A[j]);
		}		
	}
};

class LinkedList {
	struct Node {
		int data;
		Node* next;
	}*first=NULL,*t,*last;
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
			sum=sum+p->data;
			p = p->next;
		}
		return sum;
	}
	void insertNode(int x,int position) {//the node count starts from 1 and not 0
		if (position == 1) {
			Node* t=new Node;
			t->data = x;
			t->next = first;
			first = t;
		}
		else if(position > 1 && position < nodeCount()) {
			Node* t=new Node;
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
		int x=0;
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
	Node * search(int key) {
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
		while (p!=NULL) {
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
			q -> next = r;
		}
		first = q;
	}
};

int main() {
	

}