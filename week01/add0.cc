// To run this:
// Type two integers separated by a space and press return.
// To stop the program type two zeros: 0 0
//
#include <iostream>
#include <climits>
using namespace std;

auto add_by_1 ( int a, int b ) {
	// Keep adding 1 to a until b becomes 0.
	if (b > 0)
		while(b--)
			a++;
	else if (b < 0)
		while(b++)
			a++;
	return a;

};

auto mult ( int a, int b ) {
	// Keep adding 1 to a until b becomes 0.
	int c = a;
	if (b == 0)
		c = 0;
	else if (b > 1)
		while(--b)
			c = add_by_1(c, a);
	else if (b < 1){
		while(++b)
			c = add_by_1(c, a);
		c = -c;
	}

	return c;

};

int main() {
	int i, j, x;

	while (cin >> i >> j){
		x = mult(i, j);
		cout << i << " * " << j << " = " << x << endl;
	}

	cout << i << " * " << j << " = " << mult(i, j) << endl;

	return 0;
}
