/*
  Write a short program to simulate a ball being dropped off of a tower.
  To start, the user should be asked for the height of the tower in meters.
  Assume normal gravity (9.8 m/s2), and that the ball has no initial velocity
  (the ball is not moving to start). Have the program output the height of the
  ball above the ground after 0, 1, 2, 3, 4, and 5 seconds.
  The ball should not go underneath the ground (height 0).

Use a function to calculate the height of the ball after x seconds.
The function can calculate how far the ball has fallen after x seconds
using the following formula:
distance fallen = gravity_constant * x_seconds2 / 2

Desired output:

Enter the height of the tower in meters: 100
At 0 seconds, the ball is at height: 100 meters
At 1 seconds, the ball is at height: 95.1 meters
At 2 seconds, the ball is at height: 80.4 meters
At 3 seconds, the ball is at height: 55.9 meters
At 4 seconds, the ball is at height: 21.6 meters
At 5 seconds, the ball is on the ground.

*/
#include <common_includes.h>
#include <height_calc.h>

int main() {
    std::regex m_reg{ "^[0-9]{2,3}$" }; // Validate user supplied param
    double meters{}, gravity{ 9.8 };
    std::string user_input{};
    bool looper{ 0 };
    while (!looper)
    {
        std::cout << "Enter the tower height (in meters) => ";
        std::getline(std::cin >> std::ws, user_input);
        if (validateInput(user_input, m_reg)) {
            looper = 1;
            meters = std::stod(user_input);
            heightCalc(meters, gravity);
        }
        else
        {
            std::cout << "Invalid input\n";
        }
    }

    return 0;
}

