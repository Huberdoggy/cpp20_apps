#include <common_includes.h>

using namespace std;

double runImperial() {
	double pounds{}, inches{};
	cout << "\nPlease enter your weight in pounds: "; cin >> pounds;
	cout << "\nAnd now your height in inches: "; cin >> inches;
	double formula = pounds * 703 / (inches * inches);
	return formula;
}

double runMetric() {
	double kilos{}, meters{};
	cout << "\nPlease enter your weight in kilograms: "; cin >> kilos;
	cout << "\nAnd now your height in meters: "; cin >> meters;
	double formula = kilos / (meters * meters);
	return formula;
}

int main()
{
	double result{};
	char choice{};

	cout << "\t\t**** BMI CALCULATOR ****" << endl;
	cout << "\n\nWould you like to use the imperial or metric system (i/m)? "; cin >> choice;
	choice == 'i' || choice == 'I' ? result = runImperial() : result = runMetric();

	if (result < 18.5) {
		printf("\nYour BMI is %.2f. That's considered UNDERWEIGHT.", result);
	}
	else if (result >= 18.5 && result <= 24.9) {
		printf("\nYour BMI is %.2f. That's considered NORMAL.", result);
	}
	else {
		printf("\nYour BMI is %.2f. That's considered OVERWEIGHT.", result);
	}
	return 0;
}

