#include <iostream>
class Recursion {
public:
	Recursion(int x,bool ascending=true,int interval=1) {//Defaults to ascending with an interval of one
		display(x,ascending,interval);
		std::cout << std::endl;
	}
private:
	void display(int x, bool ascending,int interval) {
		if (x > 0) {
			if (ascending) {//Prints on return.
				display(x - interval, ascending,interval);
				std::cout << x << "\t";
			}
			else {//Prints before recursion function call.
				std::cout << x << "\t";
				display(x - interval, ascending,interval);
			}
		}
	}
};
int main() {
	Recursion recursion(10,true,1); //Using recursion to print in both ascending and descending with a specific interval.
}