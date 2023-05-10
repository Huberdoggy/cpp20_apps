/*
Write a function that accepts a pointer to a C-string as an argument and returns
the number of words contained in the string. For instance, if the string
argument is “Four score and seven years ago” the function should return the
number 6. Demonstrate the function in a program that asks the user to input a
string and then passes it to the function. The number of words in the string
should be displayed on the screen.

Optional Exercise: Write an overloaded version of this function that accepts a
string class object as its argument
*/

#include "common_includes.h"

int showWordCount(const char* strPtr, const char = ' '); // Default arg in declaration
int showWordCount(const std::string& usrStr, const char = ' '); // Overload

int main() {

    constexpr unsigned s{ 50 };
    char goAgain;
    std::string suffix; // To store singular or plural value of result output msg
    do
    {
        // Init array to store C-str & std string. Re-assign each loop
        char cStr[s];
        std::string stdStr;

        std::cout << "Enter a string (Up to " << s << " characters): ";
        std::cin.getline(cStr, s);
        stdStr = cStr; // Make the values equivalent
        int numWords = showWordCount(cStr);
        suffix = (numWords == 1) ? "word" : "words";

        printf("The C-String you entered '%s' has %d %s\n",
            cStr, numWords, suffix.c_str());
        printf("The STD STRING you entered '%s' also has %d %s\n",
           stdStr.c_str(), numWords, suffix.c_str());

        std::cout << "Enter a new string [Y/N]? => ";
        std::cin.get(goAgain);
        ignoreExtraneous(); // Flush buffer to immediately call getline again from the top
    } while (toupper(goAgain) == 'Y');

    return 0;
}


int showWordCount(const char* strPtr, const char delim) {

    int count{ 0 };

    if (strlen(strPtr) == 0) return count;


    while (*strPtr != '\0')
    {
        if (*strPtr == delim)
        {
            count++;

        }
        strPtr++; // Continue to advance position in memory
    } // end while

    return count + 1; // Account for the final word befor null terminator
}


int showWordCount(const std::string& usrStr, const char delim) {
    int count{ 0 };
    size_t len = usrStr.length();

    if (len == 0) return count;


    for (int i = 0; i < usrStr.length(); i++)
    {
        if (usrStr[i] == delim) {
            count++;
        }
    } // end for

    return count + 1;
}