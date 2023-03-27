#include <common_includes.h>
using namespace std;

double ctok(double c) // converts Celsius to Kelvin
{
	// Throw the error here and attempt to catch in main()
	return (c <= -273.15) ? throw runtime_error("Error, your value would equate BELOW 'absolute zero' on the KELVIN scale") : (c + 273.15);
}

double ktoc(double c) // converts Celsius to Kelvin
{
	return (c < 0) ? throw runtime_error("Error, resulting value would equate BELOW 'absolute zero' on the CELCIUS scale") : (c - 273.15);
}



int main()
{
	try {
		char input{}; // declare input variable
		double c{}, k{};
		cout << "What unit do you wish to convert to? (c, k)? "; cin >> input;
		switch (input)
		{
		case 'k':
			cout << "Please enter the desired temp in degrees Celcius: "; cin >> c;
			k = ctok(c);
			printf("\n\nTemperature converted to Kelvin is %.2f", k);
			break;
		case 'c':
			cout << "Please enter the desired temp in degrees Kelvin: "; cin >> k;
			c = ktoc(k);
			printf("\n\nTemperature converted to Kelvin is %.2f", c);
			break;
		}
	}
	catch (runtime_error& e)
	{
		cout << "\nException occured " << '\n' << e.what();
		return 1;
	}

	return 0;
}

