#include <iostream>
#include <vector>

/* TODO
- fix -1, 1/1, -1 bug
*/

// function to produce a fibonacci sequence using two arbitrary initial values
void fibonacci(int& x, int& y, std::vector<int>& v, int n){
	int t = 0;

	// filter out nonsense inputs (eg: -1, -1, 300)
	if (n > x + y && x + y >= 0) {
		v.push_back(x);	// populate v with our initial variables
		v.push_back(y);
		while (x + y <= n){
			t = x + y;
			x = y;
			y = t;
			v.push_back(t);
		}
	}
	else if (n < x + y && x + y <= 0) {
		v.push_back(x);
		v.push_back(y);
		while (x + y >= n){
			t = x + y;
			x = y;
			y = t;
			v.push_back(t);
		}
	}
	else std::cout << "Bad input\n";
}


int main(){
	// declare & initialize our variables
	std::vector<int> vfibonacci;
	int a = 0;
	int b = 1;
	int n = 0;

	std::cout << "Please provide two integers to start the sequence, ";
	std::cout << "as well as an upper bound to stop counting at.\n";
	
	std::cin >> a >> b >> n;

	fibonacci(a, b, vfibonacci, n);
	// only call cout if there's anything to print, otherwise exit
	if (vfibonacci.size() > 0) {
		for (int i =0; i < (vfibonacci.size() -1); ++i)
			std::cout << vfibonacci[i] << ", ";

		// print the last element, with slightly different formatting
		std::cout << vfibonacci.back() << ".";
		std::cout << std::endl;
	}
	return 0;
}
