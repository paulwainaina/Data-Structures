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
int main() {
	Recursion recursion;
	recursion.display(10);//Using recursion to print in both ascending and descending with a specific interval.
}