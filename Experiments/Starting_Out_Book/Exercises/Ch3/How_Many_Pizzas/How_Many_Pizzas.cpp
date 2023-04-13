/*
Joe’s Pizza Palace needs a program to calculate the number of slices a pizza
of any size can be divided into. The program should perform the following steps:
A) Ask the user for the diameter of the pizza in inches.
B) Calculate the number of slices that may be taken from a pizza of that size.
C) Display a message telling the number of slices.

To calculate the number of slices that may be taken from the pizza,
you must know the following facts :
    Each slice should have an area of 14.125 inches.
    To calculate the number of slices,
    simply divide the area of the pizza by 14.125.
    NOTE : π is the Greek letter pi = 3.14159

Make sure the output of the program displays the number of slices in
fixed point notation, rounded to one decimal place of precision.
Use a named constant for pi.

Modify the program you wrote in Programming Challenge 18 (Pizza Pi) so that it
reports the number of pizzas you need to buy for a party if each person
attending is expected to eat an average of four slices.
The program should ask the user for the number of people who will be at the
party and for the diameter of the pizzas to be ordered.
It should then calculate and display the number of pizzas to purchase.
 */

#include "common_includes.h"
 // Init a global consts for Pi & area per pizza slice, according to instructions
constexpr double PI{ 3.14159 };
constexpr double PER_SLICE_AREA{ 14.125 };
// and const expected consumption per person
constexpr int EXPECTED_CONSUMPTION_PP{ 4 };
// Forward dec for getNumSlices
inline double getNumSlices(const double& pizza_area);

double getPizzaArea(const double& radius) {
    // Call getNumSlices after calculating pizza area
    double pizza_area = PI * (radius * radius);
    return (getNumSlices(pizza_area));
}


inline double getNumSlices(const double& pizza_area) {
    // Return num of slices
    return pizza_area / PER_SLICE_AREA;
}

inline double getNumPizzas(const int& people, const double& num_slices) {
    return (static_cast<double>(EXPECTED_CONSUMPTION_PP) * people) / num_slices;
}

int main() {
    // Init variables to hold diameter and eventual radius
    double diameter{}, radius{};
    // And num people
    int people{};
    std::cout << "Enter the desired diameter of the pizza (in inches) => ";
    std::cin >> diameter;

    // Get radius
    radius = diameter / 2;
    double num_slices = getPizzaArea(radius);
    printf("Approximate number of slices that may be taken\n"\
"from a pizza of %.1f inches: %.1f\n", diameter, num_slices);
    std::cout << "How many people are expected => ";
    std::cin >> people;
    double total_pizzas = getNumPizzas(people, num_slices);
    (total_pizzas >= 0 && total_pizzas < 1) ? total_pizzas = 1 : total_pizzas;
    printf("\nYou will need %.0f pizzas for %d people\n", total_pizzas, people);
    return 0;
}

