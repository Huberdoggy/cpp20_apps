/*
Write a program that stores the following values in five different variables:
28, 32, 37, 24, and 33.
The program should first calculate the sum of these five variables and store
the result in a separate variable named sum. Then, the program should divide
the sum variable by 5 to get the average. Display the average
on the screen.
*/

#include "common_includes.h"

inline double calcAvg(double sum, const size_t len)
{
    return (sum / len);
}

std::vector<double> calcSum(const std::vector<double>& num_v)
{
    std::vector<double> ret_v;
    double sum{ 0.0 };
    for (auto& i : num_v)
    {
        sum += i;
    }

    ret_v.push_back(sum);
    ret_v.push_back(calcAvg(sum, num_v.size()));
    return ret_v;
}

int main()
{

    std::vector<double> num_v{ 28.0, 32.0, 37.0, 24.0, 33.0 };

    std::vector<double> results = calcSum(num_v);
    std::cout << "The sum of all values is: " << results[0] << '\n';
    std::cout << "And the average is: " << results[1] << '\n';
    std::string str = "";

    return 0;
}
