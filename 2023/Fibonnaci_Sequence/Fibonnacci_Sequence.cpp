/*
Write a program that writes out the first so many values of the Fibonacci
series, that is, the series that starts with 1 1 2 3 5 8 13 21 34.
The next number of the series is the sum of the two previous ones.
Find the largest Fibonacci number that fits in an int.
*/

# include "common_includes.h"

std::vector<unsigned> fibSeries(std::vector<unsigned>& v) {
    unsigned previous{ 0 };
    unsigned next{ 0 };
    unsigned added{ 0 };
    for (int i = 0; i < v.size(); i++)
    {
        if (i >= 1)
        {
            added = i + 1; // Get next index #
            previous = i - 1; // And the most recent
            next = v[i] + v[previous]; // Add the values
            v.resize(v.size() + 1); // Continuously increase size by 1
            // when the final initialized val has been reached
            // and continue this
            if (next >= INT_MAX) // Can go higher with unsigned, but can't
                // get logic to print up to UINT_MAX for now, just cutting off
                // at 2_147_483_647
            {
                next = INT_MAX;
                v[added] = INT_MAX;
                break;
            }
            v[added] = next; // Assign the sum to the new index
        }


    }
    return v;
}

unsigned main() {

    unsigned num1{ 0 }, num2{ 0 }; // should approximately allow 
    // up to 4_294_967_296 (no sign, so 2^32)
    std::cout <<
        "Enter two numbers, and I will use them as the starting point\n"
        "to calculate a Fibonacci series:\n";
    std::cin >> num1;
    std::cin >> num2;
    std::vector<unsigned> v{ num1, num2 };

    fibSeries(v);
    for (auto i : v)
    {
        std::cout << "Sequence number: " << i << '\n';
    }
    return 0;
}

