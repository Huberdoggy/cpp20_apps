/*
Write a program that asks the user for the number of males
and the number of females registered in a class.
The program should display the percentage of males and females in the class.
Hint: Suppose there are 8 males and 12 females in a class.
There are 20 students in the class.
The percentage of males can be calculated as 8 ÷ 20 = 0.4, or 40%.
The percentage of females can be calculated as 12 ÷ 20 = 0.6, or 60%.
*/

#include <iomanip>
# include "common_includes.h"

unsigned short getNum(const std::string& prompt =
    "Enter the number of males in the class") {
    // Override prompt for females
    std::string str; // Hold str val of 'males' and 'females'
    const std::regex re("^\\d{1,3}$"); // I'm allowing up to 3 digits only
    std::cout << prompt << " => ";
    std::cin >> str;
    if (std::regex_match(str, re)) return static_cast<short>(std::stoi(str)); // convert

    std::cout << "ERROR! Input is not an integer!\n";
    // Recurse function call
    return getNum(prompt);
}

float calcPercentage(const short personnel, const short total) {

    return (total > 0) ? static_cast<float>(personnel) / total : // Need one 
        // operand to cast float to avoid truncation
        throw std::exception("Nothing to calculate!");
}

int main() {

    unsigned short total{ 0 };
    std::string prompt_female = "Enter the number of females in the class";

    unsigned short males{ getNum() };
    unsigned short females{ getNum(prompt_female) };

    try
    {
        total = males + females;
        float p_m = calcPercentage(males, total) * 100;
        float p_f = calcPercentage(females, total) * 100;

        printf
        ("Percentage of males out of class size %d: %.1f\n", total, p_m);
        printf
        ("Percentage of females out of class size %d: %.1f\n", total, p_f);
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }

}

