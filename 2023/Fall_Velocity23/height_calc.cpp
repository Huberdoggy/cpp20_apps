#include <common_includes.h>
#include <height_calc.h>

void printResult(int seconds, double nm) {
    if (seconds == 0) {
        printf("\nAt the start, the ball is at height %.0f meters\n", nm);
    }
    else if (nm >= 0) {
        seconds == 1 ? printf("After %d second, "
            "the ball is at height %.1f meters\n", seconds, nm) :
            printf("After %d seconds, " 
                "the ball is at height %.1f meters\n", seconds, nm);
    }
    else {
        printf("After %d seconds, the ball is on the ground.\n", seconds);
    }
}

double heightCalc(double m, const double g) {
    double d_fallen{}, new_meters{};
    int seconds{ 0 };

    for (int i = 0; i < 6; i++)
    {
        d_fallen = g * (pow(seconds, 2) / 2);
        new_meters = m - d_fallen;
        printResult(seconds, new_meters);
        seconds++;

    }
    return 0;
}
