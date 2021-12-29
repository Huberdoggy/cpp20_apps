/*
Reminder of multi-line comment syntax in C/C++
*/

// VS hotkeys
// Save All - Cntrl+SHIFT+S
// To comment highlighted area = Cntrl+K,Cntrl+C
// And to uncomment = Cntrl+K,Cntrl+U
// For auto-formatting entire file - Cntrl+K,Cntrl+D

#include <iostream>
#include <string>
#include <cstdlib>
// Added an exclusion for warning 4996 in Properties => C++, so as to allow deprecated 'getenv' function to test this out
using std::cout; using std::getenv;
using std::string; using std::cerr;


const char* USR_VAR = "USERNAME"; // instantiate constant to hold environmental var value so that it can't be modified

int main()
{
	const char* tmp = getenv("USERNAME"); // accepts string param - needs to be uppercase so as to match the Windows env variable
	string usr_var(tmp ? tmp : "");
	if (usr_var.empty())
	{
		cerr << "[!] ERROR. Can't find environmental variable for $USERNAME on Kyle's VM.\n";
		exit(EXIT_FAILURE);
	}

	std::cout << "Hello " << usr_var << '\n';
	int chosen_num{};
	std::cout << "Enter your desired number => ";
	std::cin >> chosen_num;
	std::cout << "\nNow calculating the double of " <<
		chosen_num << ": " << chosen_num * 2 << '\n' <<
		"And the triple value is: " << chosen_num * 3;
	/* if (area >= 30)
	 {
	 std::cout << "\nThe area is " << area << " which is greater than 30\n";

	 }
	 else
	 {
		 std::cout << "The area is " << area << " which is LESS than 30\n";
	 }
 exit(EXIT_SUCCESS);*/
	return 0;
}

