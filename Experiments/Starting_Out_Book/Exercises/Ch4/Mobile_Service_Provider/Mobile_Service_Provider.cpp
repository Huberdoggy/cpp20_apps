/*
Mobile Service Provider
A mobile phone service provider has three different subscription packages for
its customers:

Package A: For $39.99 per month 450 minutes are provided.
Additional minutes are $0.45 per minute.

Package B: For $59.99 per month 900 minutes are provided. Additional minutes are
$0.40 per minute.

Package C: For $69.99 per month unlimited minutes provided.

Write a program that calculates a customer’s monthly bill.
It should ask which package the customer has purchased and how many minutes
were used. It should then display the total amount due.
Input Validation: Be sure the user only selects package A, B, or C.

Mobile Service Provider, Part 2
Modify the Program in Programming Challenge 25 so that it also displays how much
money Package A customers would save if they purchased packages B or C, and how
much money Package B customers would save if they purchased Package C. If there
would be no savings, no message should be printed.

Mobile Service Provider, Part 3
Months with 30 days have 720 hours, and months with 31 days have 744 hours.
February, with 28 days, has 672 hours. You can calculate the number of minutes in
a month by multiplying its number of hours by 60. Enhance the input validation of
the Mobile Service Provider program by asking the user for the month (by name), and
validating that the number of minutes entered is not more than the maximum for
the entire month. Here is a table of the months, their days,
and number of hours in each.

Month Days Hours
January 31 744
February 28 672
March 31 744
April 30 720
May 31 744
June 30 720
July 31 744
August 31 744
September 30 720
October 31 744
November 30 720
December 31 744

*/

#include "common_includes.h"

// CONSTANTS
constexpr float A_PKG_PRICE{ 39.99f }, B_PKG_PRICE{ 59.99f },
C_PKG_PRICE{ 69.99f };
constexpr float A_PROVIDED_MIN{ 450.0f }, B_PROVIDED_MIN{ 900.0f },
A_PKG_ADDL{ 0.45f }, B_PKG_ADDL{ 0.4f };


float calcTotalBill(const char chosen_pkg, int mins_used) {
    switch (chosen_pkg)
    {
        // If used mins is greater then that provided by pkg,
        // subtract used mins from provided, multiply that by the addl per min
        // price & add to base pkg price
    case 'a': case 'A':
        return (mins_used > A_PROVIDED_MIN) ?
            A_PKG_PRICE + ((mins_used - A_PROVIDED_MIN) * A_PKG_ADDL)
            : A_PKG_PRICE;
        break;
    case 'b': case 'B':
        return (mins_used > B_PROVIDED_MIN) ?
            B_PKG_PRICE + ((mins_used - B_PROVIDED_MIN) * B_PKG_ADDL)
            : B_PKG_PRICE;
        break;
    default:
        return C_PKG_PRICE;
    }
}

void calcSavings(const char chosen_pkg, int mins_used,
    const float total) {

    float b_diff{ total - B_PKG_PRICE }, c_diff{ total - C_PKG_PRICE };
    switch (chosen_pkg)
    {
    case 'a': case 'A':
        if (mins_used > A_PROVIDED_MIN && mins_used <= B_PROVIDED_MIN && total > B_PKG_PRICE)
        {
            std::cout << std::fixed << std::setprecision(2) <<
                "\nWith the B Plan you would save: " << '$' << b_diff << "\n";
        }
        else if (mins_used > B_PROVIDED_MIN) {
            std::cout << std::fixed << std::setprecision(2) <<
                "\nWith the C Plan you would save: " << '$' << c_diff << "\n";
        }
        break;
    case 'b': case 'B':
        if (mins_used > B_PROVIDED_MIN && total > C_PKG_PRICE)
        {
            std::cout << std::fixed << std::setprecision(2) <<
                "\nWith the C Plan you would save: " << '$' << c_diff << "\n";
        }
        break;
    default:
        break;
    }
}

inline bool validatePkgChoice(const char chosen_pkg) {
    switch (chosen_pkg)
    {
    case 'a': case 'A': case 'b': case 'B': case 'c': case 'C':
        return 1;
    default:
        return 0; // Invalid option
    }
}


inline bool validateMinutesUsed(const int minutes) {
    return (minutes >= 0) ? 1 : 0;
}


int main() {

    // User input initializers
    char chosen_pkg{};
    int minutes_used{ 0 };
    float total{ 0.0f };

    // Flip 'fill' to use special formatting dash prior to change backto ' '
    std::cout << std::setw(50) << "AVAILABLE PHONE Packages\n";
    std::cout << std::setfill('-') << std::setw(80) << '\n';
    std::cout << std::setfill(' ') << "PLAN" << std::setw(25);
    std::cout << "PRICE/MO" << std::setw(25);
    std::cout << "MINUTES PROVIDED" << std::setw(25);
    std::cout << "ADDITIONAL CHARGE/MIN" << "\n\n";

    std::cout << "A" << std::setw(25) << "$39.99" <<
        std::setw(25) << "450" << std::setw(25) << "$0.45\n";
    std::cout << "B" << std::setw(25) << "$59.99" <<
        std::setw(25) << "900" << std::setw(25) << "$0.40\n";
    std::cout << "C" << std::setw(25) << "$69.99" <<
        std::setw(25) << "Unlimited" << std::setw(25) << "N/A\n\n";

    // Get input from user - purchased package & num minutes used
    std::cout << "Please enter which package you've purchase [A, B, C] => ";
    std::cin >> chosen_pkg;

    while (!(validatePkgChoice(chosen_pkg))) {
        std::cout << "\n\nPlease choose a valid option";
        ignoreExtraneous(); // ignore numeric limits including newline
        std::cout << "\n=> "; // the cout new prompt
        std::cin.get(chosen_pkg);
    }

    std::cout << "\n\nAnd how many minutes did you use?\n=> ";
    std::cin >> minutes_used;
    while (!(validateMinutesUsed(minutes_used))) // Don't allow impossibilites
    {
        std::cout << "Please enter zero or greater\n=> ";
        std::cin >> minutes_used;
    }

    total = calcTotalBill(chosen_pkg, minutes_used);
    std::cout << std::fixed << std::setprecision(2) <<
        "Your total bill this month is: " << '$' << total << std::endl;

    // Would there be savings with a pkg upgrade?
    calcSavings(chosen_pkg, minutes_used, total);

    return 0;
}

