/*
The date June 10, 1960 is special because when we write it in the following
format, the month times the day equals the year:

6/10/60

Write a program that asks the user to enter a month (in numeric form),
a day, and a two-digit year. The program should then determine whether
the month times the day is equal to the year. If so, it should display a message
saying the date is magic. Otherwise it should display a message saying
the date is not magic.
*/

#include "common_includes.h"

inline bool determineMagic(const std::vector<int>& date_v) {
    return (date_v[0] * date_v[1] == date_v[2]) ? 1 : 0;
}

int main() {
    constexpr int ALLOWED_SIZE{ 3 };
    std::vector<int> date_v{};
    std::string century{"19"};
    int count{ 0 };
    bool isMagic{};
    std::cout << "Enter a month a day, and a year [M DD YY]\n"
        << "Press '|' to stop anytime\n";

    for (int entry; std::cin >> entry;)
    {

        if (count < ALLOWED_SIZE)
        {
            date_v.push_back(entry);
            count++;
        }
        else
        break; // If they don't send termination char prematurely
    }

    if (date_v.size() == ALLOWED_SIZE) {
        isMagic = determineMagic(date_v);
        (date_v[2] <= 23) ? century = "20" : century; // My temp solution to make formatting nicer
        std::cout << "Is year " << century << date_v[2] << " a magic year?\n" <<
            "VERDICT: " << std::boolalpha << isMagic << '\n';
        return 0;
    }
    else
    {
        // We don't have enough figures to call the function
        std::cerr << "Can't calculate based on " << date_v.size()
            << " supplied args" << std::endl;
        return 1;
    }
}

