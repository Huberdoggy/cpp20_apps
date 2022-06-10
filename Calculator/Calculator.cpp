/*
Reminder of multi-line comment syntax in C/C++
*/

// VS hotkeys
// Save All - Cntrl+SHIFT+S
// To comment highlighted area = Cntrl+K,Cntrl+C
// And to uncomment = Cntrl+K,Cntrl+U
// For auto-formatting entire file - Cntrl+K,Cntrl+D


#include <iostream>
#include <math.h>
#include <Windows.h>
using namespace std;


float add(float _num1, float _num2) {
	float result = _num1 + _num2;
	return result;
}

float subtract(float _num1, float _num2) {
	float result = _num1 - _num2;
	return result;
}

float multiply(float _num1, float _num2) {
	float result = _num1 * _num2;
	return result;
}

float divide(float _num1, float _num2) {
	float result{};
	return _num2 > 0 ? result = _num1 / _num2 : 7; // Custom value to identify error
}

int modulus(float _num1, float _num2) {
	int result = (int(_num1) % int(_num2)); // Attempt to cast - will drop decimal portion
	return result;
}


int main(float _num1, float _num2)
{
	float num1 = 0, num2 = 0, add_res{}, sub_res{}, mult_res{}, div_res{};
	int mod_res = 0;
	char _operator{};
	string response{};
	bool goAgain = true, isNumeric = true;

	cout << "*** WELCOME TO KYLE'S C++ CALCULATOR ***" << endl;
	while (goAgain) {
		cout << "\n\nPlease enter the first number => "; cin >> num1;
		sizeof(num1) == 4 && cout << "\nChoose your mathematical operation (+, -, /, *, %) => "; cin >> _operator;
		cout << "\nAnd now the second number please => "; cin >> num2;

		switch (_operator)
		{
		case '+':
			add_res = add(num1, num2);
			printf("Result of the ADDITION is %.2f", add_res);
			break;
		case '-':
			sub_res = subtract(num1, num2);
			printf("\nResult of the SUBTRACTION is %.2f", sub_res);
			break;
		case '*':
			mult_res = multiply(num1, num2);
			printf("\nResult of the MULTIPLICATION is %.2f", mult_res);
			break;
		case '/':
			div_res = divide(num1, num2);
			if (div_res != 7)
			{
				printf("\nResult of the DIVISION is %.2f", div_res);
			}
			else {
				cout << "\nERROR! You attempted to divide by zero. This is not allowed.";
			}
			break;
		case '%':
			mod_res = modulus(num1, num2);
			printf("\nResult of the MODULATION is %d", mod_res);
			break;
		default:
			cout << "Invalid operator. Please choose from the defined options in prompt.";
			break;
		}

		Sleep(3000);
		system("cls");
		cout << "\n\nNew calculation?? => "; cin >> response;
		if (response == "n" || response == "N")
		{
			cout << "Okay. Good-bye now!";
			goAgain = false;
		}

	}
	return 0;
}