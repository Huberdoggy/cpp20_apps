/*
In a population, the birth rate is the percentage increase of the population due
to births, and the death rate is the percentage decrease of the population due
to deaths. Write a program that displays the size of a population for any number
of years. The program should ask for the following data:
• The starting size of a population
• The annual birth rate
• The annual death rate
• The number of years to display
Write a function that calculates the size of the population for a year.
The formula is N = P + BP − DP where N is the new population size, P is the
previous population size, B is the birth rate, and D is the death rate.

Do not accept numbers less than 2 for the starting size. Do not accept
negative numbers for birth rate or death rate. Do not accept numbers less than 1 for
the number of years.

*/

#include "common_includes.h"

int verifyInputMinimums(int& user_input, const int min_required,
    const std::string_view err_msg);

// Overload for differing parameter data types
float verifyInputMinimums(float& user_input, const float min_baseline,
    const std::string_view err_msg);

float calcPopulation(int start_size, float birth_rate, float death_rate, 
    int num_years);


int main() {
    // Constants baselines
    constexpr int MIN_YEARS{ 1 };
    constexpr int MIN_START_POP{ 2 };
    constexpr float BASE_BIRTH_RATE{ 0.0f }, BASE_DEATH_RATE{ 0.0f };

    // Init variables for birth/death rate, num_years, and starting pop. size
    int start_size, num_years;
    float birth_rate{ 0.0f }, death_rate{ 0.0f }; // Explicit floats

    /*******************String error messages*********************************/
    std::string years_err =
        "ERROR! Minumum number of years must be at least " +
        std::to_string(MIN_YEARS) + " year.";
    std::string pop_size_err =
        "ERROR! Minumum population must be at least " +
        std::to_string(MIN_START_POP) + " people.";
    std::string br_err = "ERROR! Birth rate must be at least "
        + std::to_string(BASE_BIRTH_RATE);
    std::string dr_err = "ERROR! Death rate must be at least "
        + std::to_string(BASE_DEATH_RATE);
    /************************************************************************/

    std::cout << "Enter the starting size of the population => ";

    verifyInputMinimums(start_size, MIN_START_POP, pop_size_err);
    std::cout << "And how many years do you wish to inspect? => ";

    verifyInputMinimums(num_years, MIN_YEARS, years_err);
    std::cout << "Now, please provide the annual birth rate (as a decimal) => ";

    verifyInputMinimums(birth_rate, BASE_BIRTH_RATE, br_err); // For tidiness, seperate for birth & death rates
    std::cout << "And finally, the annual death rate (as a decimal) => ";

    verifyInputMinimums(death_rate, BASE_DEATH_RATE, dr_err);

    // Birth/death rate are expressed as percentages
    birth_rate /= 100;
    death_rate /= 100;

    // Set up formula for determining pop size - pass to function for calc
    float new_pop = calcPopulation(start_size, birth_rate, death_rate, num_years);
    std::cout << std::fixed << std::setprecision(0) 
        << "The anticipated new population after " << num_years << 
        (num_years > 1 ? " years" : " year") << ": " << 
        (new_pop > 0.0 ? new_pop : 0) << " people\n";

    return 0;
}


int verifyInputMinimums(int& user_input, const int min_required,
    const std::string_view err_msg) {

    while (!(std::cin >> user_input) || user_input < min_required)
    {
        std::cin.clear(); // Since condition set for !cin, this will clear flag
        // on incorrect data type entries
        ignoreExtraneous(); // And this will clear buffer up to new line
        std::cout << err_msg << "\n=> ";
    }
    return user_input; // Return reference to cin input
}

float verifyInputMinimums(float& user_input, const float min_required,
    const std::string_view err_msg) {

    while (!(std::cin >> user_input) || user_input < min_required)
    {
        std::cin.clear();
        ignoreExtraneous();
        std::cout << err_msg << "\n=> ";
    }
    return user_input;
}


float calcPopulation(int start_size, float birth_rate, 
    float death_rate, int num_years)
{
    float change_factor = (birth_rate * static_cast<float>(start_size)) - 
        (death_rate * static_cast<float>(start_size));
    float new_pop = start_size + (change_factor * num_years);
    return new_pop;
}