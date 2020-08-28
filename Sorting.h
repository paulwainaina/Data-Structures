#pragma once
class Sorting {
public:
	int *A, n;
	Sorting(int A[], int n) {
		this->A = A;
		this->n = n;
	}
	void swap(int *x, int* y) {
		int tmp = *x;
		*x = *y;
		*y = tmp;
	}
	void bubbleSort() {
		int i, j;
		bool flag = false;
		for (i = 0;i < n - 1;i++) {
			flag = false;
			for (j = 0;j < n - i - 1;j++) {
				if (A[j] > A[j +1 ]) {
					swap(&A[j], &A[j+1]);
					flag = true;
				}
			}
			if (!flag) {//check if elements are already sorted
				break;
			}
		}
	}
	void insertSort() {
		int i, j, x;
		for (i = 1; i < n;i++) {
			j = i - 1;
			x = A[i];
			while (j > -1 && A[j] > x) {
				A[j + 1] = A[j];
				j--;
			}
			A[j + 1] = x;
		}
	}
	void selectSort() {
		int i, j, k;
		for (i = 0;i < n - 1;i++) {
			for (j = k = i;j < n;j++) {
				if (A[j] < A[k]) {
					k = j;
				}
			}
			swap(&A[i], &A[k]);
		}
	}
	void quickSort(int l,int h) {
		int j;
		if (l < h) {
			j = partation(l, h);
			quickSort(l, j);
			quickSort(j + 1, h);
		}
	}
	void mergeSort() {
		int p, l, h, mid, i;
		for (p = 2;p <= n;p = p * 2) {
			for (i = 0;i + p - 1 < n;i = i + p) {
				l = i;
				h = i + p - 1;
				mid = (l + h) / 2;
				merge(A, l, mid, h);
			}
		}
		if (p / 2 < n) {
			merge(A, 0, p / 2-1, n );
		}
	}
	void shellSort() {
		int gap, i, j, temp;
		for (gap = n / 2;gap >= 1;gap /= 2) {
			for (i = gap;i < n;i++) {
				temp = A[i];
				j = i - gap;
				while (j >= 0 && A[j] > temp) {
					A[j + gap] = A[j];
					j = j - gap;
				}
				A[j + gap] = temp;

			}
		}
	}
	void countSort() {
		int i, j, max, * c;
		max = findMax();
		c = (int*)malloc(sizeof(int) * (max + 1));
		for (i = 0;i < max + 1;i++) {
			c[i] = 0;
		}
		for (i = 0;i < n;i++) {
			c[A[i]]++;
		}
		i = 0;j = 0;
		while (j < max + 1) {
			if (c[j] > 0) {
				A[i++] = j;
				c[j]--;
			}
			else {
				j++;
			}
		}
	}
	int findMax() {
		int max = INT_MIN;
		int i;
		for (i = 0;i < n;i++) {
			if (A[i] > max) {
				max = A[i];
			}
		}
		return max;
	}
	void merge(int *X,int l,int mid,int h) {
		int i=l, j=mid+1, k=l;
		int B[100];
		while (i <= mid && j <= h) {
			if (X[i] < X[j]) {
				B[k++] = X[i++];
			}
			else {
				B[k++] = X[j++];
			}
		}
		for (;i <= mid;i++) {
			B[k++] = X[i];
		}
		for (;j <= h;j++) {
			B[k++] = X[j];
		}
		for (i = l;i <= h;i++) {
			X[i] = B[i];
		}
	}
	int partation (int l, int h) {
		int pivot = A[l];
		int i = l, j = h;
		do {
			do { i++; } while (A[i] <= pivot);
			do { j--; } while (A[j] > pivot);
			if (i < j) {
				swap(&A[i], &A[j]);
			}
		} while (i < j);
		swap(&A[l], &A[j]);
		return j;
	}
	void display(){
		for (int i = 0;i < n;i++) {
			std::cout << A[i] << "\t";
		}
		std::cout << std::endl;
	}
};