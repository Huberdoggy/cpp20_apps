/*
Write a short program to simulate a ball being dropped off of a tower. To start, the user should be asked for the height of the tower in meters.
Assume normal gravity (9.8 m/s2), and that the ball has no initial velocity (the ball is not moving to start).
Have the program output the height of the ball above the ground after 0, 1, 2, 3, 4, and 5 seconds. The ball should not go underneath the ground (height 0).

Use a function to calculate the height of the ball after x seconds. The function can calculate how far the ball has fallen after x seconds
using the following formula: distance fallen = gravity_constant * x_seconds2 / 2

Desired output:
Enter the height of the tower in meters: 100
At 0 seconds, the ball is at height: 100 meters
At 1 seconds, the ball is at height: 95.1 meters
At 2 seconds, the ball is at height: 80.4 meters
At 3 seconds, the ball is at height: 55.9 meters
At 4 seconds, the ball is at height: 21.6 meters
At 5 seconds, the ball is on the ground.
Note: Depending on the height of the tower, the ball may not reach the ground in 5 seconds -- that’s okay. We’ll improve this program once we’ve covered loops.
Note: The ^ symbol isn’t an exponent in C++. Implement the formula using multiplication instead of exponentiation.
Note: Remember to use double literals for doubles, eg. 2.0 rather than 2.
*/

#include <quick_headers.h> // Can add to 'include path from solution > properties to use < > notations instead of relative path "../.." etc
using namespace std;

void calcVelocity(double m) {
	int seconds = 0;
	constexpr double gravity{ 9.8 };
	// Loop from zero to five seconds, and calc the ball's height at each instance
	while (seconds < 6)
	{
		if (seconds == 0) {
			printf("\nAt %d seconds, the ball is at height: %.1f meters", seconds, m);
		}

		else {
			const double d_fallen{ gravity * (seconds * seconds) / 2.0 };
			const double height{ m - d_fallen }; // anything between 1 and 5 seconds - subtract d_fallen from initial height
			height >= 0 ? printf("\nAt %d seconds, the ball is at height: %.1f meters", seconds, height) : printf("\nAt %d seconds the ball is on the ground", seconds);
		}
		seconds++;
	}

}

int main()
{
	double meters{};
	cout << "Enter the height of the tower in meters: "; cin >> meters;
	calcVelocity(meters);
	return 0;
}

