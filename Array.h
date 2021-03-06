#pragma once
template<class T>
class Array {
public:
	T* A;
	int length, size;
	Array(int s) {
		size = s;
		A = (T*)malloc(size * sizeof(T));
		length = 0;
	}
	~Array() {
		free(A);
	}
	void addElement(T t) {
		if (length < size) {
			A[length] = t;
			length++;
		}
		else {
			std::cout << "Array is Full : Array size: " << size << std::endl;
		}
	}
	void insertElement(int index, T t) {
		if (length < size && index < size && index >= 0) {
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
			A[index] = t;
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
		T total = 0;
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
			std::cout << "Index out of range: Array length: " << length - 1 << std::endl;
		}
	}
	int linearSearchElement(T t) {
		for (int i = 0;i < length;i++) {
			if (t == A[i]) {
				swap(&A[i], &A[(i - 1)]);//improve the search by transposition => the more it is searched the more it moves closer to the first index.
				return i - 1;
			}
		}
		return -1;
	}
	int binarySearchElement(T t) {//works only if elements are sorted
		int low = 0, high = length - 1, mid;
		while (low <= high) {
			mid = (low + high) / 2;
			if (t == A[mid]) {
				return mid;
			}
			else if (t == A[low]) {
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
	void swap(T* x, T* y) {
		T temp;
		temp = *x;
		*x = *y;
		*y = temp;
	}
	void displayArray() {
		for (int i = 0;i < length;i++) {
			std::cout << A[i] << "\t";
		}
		std::cout << std::endl;
	}
	void reverseArray() {
		int i, j;
		for (i = 0, j = length - 1;i < j;i++, j--) {
			swap(&A[i], &A[j]);
		}
	}
	bool isSorted() {
		int x;
		for (x = 0;x < length;x++); {
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
		else {
			std::cout << "Array is Full : Array size: " << size << std::endl;
		}
	}
	void rearrangePositiveNegative() {
		int i = 0, j = length - 1;
		while (i < j) {
			while (A[i] < 0)i++;
			while (A[i] >= 0)j--;
			if (i < j)swap(&A[i], &A[j]);
		}
	}
};