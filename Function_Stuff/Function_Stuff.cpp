#include <iostream>
//
//void printName(int age)
//{
//    // For the voided func to hold a value after execution, we declare a param
//    // and later in main, we pass it a value
//    std::cout << "Hello Kyle!" << " \nIn a few days you will be " << age;
//}
//
//int returnMult()
//{
//    std::cout << "Please enter an integer => ";
//    int input{}; // Initialize it empty
//    std::cin >> input;
//
//    return input;
//}
//
//int main()
//{
//    // Make 2 calls to returnMult() to produce a product from input
//    printName(30); std::cout << "\n\n"; // Call printName and pass my desired int
//    int num1{ returnMult() }; // Here we store the function's return vals in new vars
//    int num2{ returnMult() };
//    std::cout << "The product of " << num1 << " times " << num2 << " is: "
//        << num1 * num2;
//    return EXIT_SUCCESS; // Same as returning zero
//}
//int doubleNumber(int x) {
//	return x * 2;
//}


// Forward declaration for 'add' function in 'addition.cpp'
int add(int, int);

int main() {
	int number1{}, number2{}; // Pass to function 'add' as expected params
	std::cout << "Please enter a number => ";
	std::cin >> number1;
	std::cout << "\nAnd now one more number please => ";
	std::cin >> number2;
	std::cout << "\nThe sum of " << number1 << " and " << number2 << " is " <<
		add(number1, number2);
	return 0;

//	int number{}; // To pass into function call parameter for 'x'
//	std::cout << "Please enter an integer value => ";
//	std::cin >> number;
//	std::cout << "The product of " << number << " times two is: "
//		<< doubleNumber(number);
//	return 0;
}
