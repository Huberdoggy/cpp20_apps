/*
Quadratic equations form
ax^2 + bx + c = 0

Quadratic formula:

x = -b +- sqrt(b^2 - 4ac) / 2a

User will provide a, b, c.

Discriminant = b^2 - 4ac. If this is less than zero, the equation has 2 complex roots. Else, it has 2 real roots.

*/
#include "common_includes.h"
using namespace std;

vector<float> quadForm(float a, float b, float c) {
	float sqBTerm = b * b;
	float a_c = a * c;
	float twice_A = 2 * a;
	vector<float> v{};

	if (sqBTerm - (4 * a_c) < 0) { // Check
		throw runtime_error("\nB^2 minus 4ac is negative.\nResulting roots will be complex.");
	}
	else if (sqBTerm - (4 * a_c) == 0) {
		float singleRoot = -1 * b / twice_A;
		v.push_back(singleRoot);
		return v;
	}
	else {
		float rootOne = (-1 * b + sqrt(sqBTerm - 4 * a_c)) / twice_A; // Parenthesees MATTER here - entire eval must happen before dividing 2a
		float rootTwo = (-1 * b - sqrt(sqBTerm - 4 * a_c)) / twice_A;
		// Resulting values of x
		v.push_back(rootOne);
		v.push_back(rootTwo);
		return v;
	}
}


int main()
{
	try {
		float a{}, b{}, c{};
		cout << "\t\t***** QUADRATIC EQUATION CALCULATOR *****\n\n";
		cout << "Please provide the values for A, B, and C, delimited by spaces: "; cin >> a >> b >> c;
		vector<float> results = quadForm(a, b, c);
		for (float x : results) {
			printf("\nX = %.2f", x);
		}
	}
	catch (runtime_error& e) {
		cout << "\nException occured " << '\n' << e.what();
		return 1;
	}

	return 0;
}

