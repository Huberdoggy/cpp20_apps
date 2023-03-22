#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;


void orderNumericInput(int numArr[], int size) {
	sort(numArr, numArr + size); // using sort function from the algorithms library
	cout << "\nList after sorting is: ";
	for (int i = 0; i < size; i++)
	{
		i < 2 ? printf("%d%s", numArr[i], ", ") : printf("%d", numArr[i]); // I like using format strings where possible. Last index won't trail comma
	}
}

double getCoinValue(int length, double inputArr[]) {
	double sum = 0;
	double calcVals[6]{ 0.01, 0.05, 0.10, 0.25, 0.50, 1.00 };
	for (int i = 0; i < length; i++) {
		sum = sum + (inputArr[i] * calcVals[i]); // each iteration increment sum by multiplying the corresponding currency unit value 
		// by the num of that piece of currency passed in
	}
	return sum;
}

int main()
{
	int pennies{}, nickels{}, dimes{}, quarters{}, halfDollars{}, dollars{};
	int num1{}, num2{}, num3{};

	cout << "How many pennies do you have? "; cin >> pennies;
	cout << "How many nickels? "; cin >> nickels;
	cout << "How many dimes? "; cin >> dimes;
	cout << "How many quarters? "; cin >> quarters;
	cout << "How many half dollars? "; cin >> halfDollars;
	cout << "And finally, how many whole dollars? "; cin >> dollars;
	double inputArr[6] = { pennies, nickels, dimes, quarters, halfDollars, dollars }; // Not concerned with potential data loss here...need a double return
	int length = (sizeof(inputArr) / sizeof(inputArr[0])); // for ease of use to track i loop in above function
	cout << "\nYou have " << pennies << (pennies != 1 ? " pennies" : " penny.");
	cout << "\nYou have " << nickels << (nickels != 1 ? " nickels" : " nickel.");
	cout << "\nYou have " << dimes << (dimes != 1 ? " dimes" : " dime.");
	cout << "\nYou have " << quarters << (quarters != 1 ? " quarters" : " quarter.");
	cout << "\nYou have " << halfDollars << (halfDollars != 1 ? " half dollars" : " half dollar.");
	cout << "\nYou have " << dollars << (dollars != 1 ? " dollars" : " dollar.");
	cout << "\n\nThe value of all your currency is: " << "$" << getCoinValue(length, inputArr);

	cout << "\n\nEnter 3 numbers to be sorted from smallest to largest, separated by spaces: "; cin >> num1 >> num2 >> num3;
	int sortArr[3]{ num1, num2, num3 };
	int s = (sizeof(sortArr) / sizeof(sortArr[0])); // pass this to function to track with the loop and use by 'sort' calculation
	cout << '\n';
	orderNumericInput(sortArr, s);
	return 0;
}

