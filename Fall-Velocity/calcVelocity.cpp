#include <quick_headers.h>

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