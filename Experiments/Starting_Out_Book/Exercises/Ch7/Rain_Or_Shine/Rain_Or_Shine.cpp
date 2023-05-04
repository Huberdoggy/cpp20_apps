/*
An amateur meteorologist wants to keep track of weather conditions during the
past year’s three-month summer season and has designated each day as either rainy
(‘R’), cloudy (‘C’), or sunny (‘S’). Write a program that stores this
information in a 3 × 30 array of characters, where the row indicates the
month (0 = June, 1 = July, 2 = August) and the column indicates the day of the
month. Note that data are not being collected for the 31st of any month.
The program should begin by reading the weather data in from a file.
Then it should create a report that displays, for each month and for the whole
three-month period, how many days were rainy, how many were cloudy, and
how many were sunny. It should also report which of the three months had the
largest number of rainy days. Data for the program can be found in the
RainOrShine.txt file.
*/

// NOTE - Added proj preprocessor line 
// _CRT_SECURE_NO_WARNINGS to allow std::getenv

#include "common_includes.h"

// Function declarations
inline bool testExistence(const std::ifstream& input_file);

std::vector<std::string> buildVec(std::ifstream& input_file,
    std::vector<std::string>& v);

std::vector<int> calcStatistics(const int months, const int days,
    const std::vector<std::string>& v); // Not modifying input vec here

std::string determineRowMonth(const int row);

void displayResults(const std::vector<int>& v, const int months);

// Global to map str value of month with its total int rainfall
std::pair <int, std::string> G_RAIN_PAIR(0, "foo"); // Init with garbage

/*****************************************************************************/
int main() {
    // Local Constants
    constexpr int NUM_MONTHS{ 3 };
    constexpr int NUM_DAYS{ 30 };


    std::string str_file = std::getenv("STREAMFILE_DIR");
    str_file += "\\RainOrShine.txt";
    std::ifstream input_file(str_file); // Init filestream object to read data into prog
    std::vector<std::string> v;
    if (!(testExistence(input_file))) {
        std::cout << "Error opening input file.\n";
        return 1;
    }

    buildVec(input_file, v); // Return filled array, passed by reference here
    std::vector<int> stats = calcStatistics(NUM_MONTHS, NUM_DAYS, v);
    // Display results table
    displayResults(stats, NUM_MONTHS);

    return 0;
}
/*****************************************************************************/


inline bool testExistence(const std::ifstream& input_file) {
    return (!input_file) ? false : true;
}


std::vector<std::string> buildVec(std::ifstream& input_file,
    std::vector<std::string>& v) {

    std::string line; // Hold space delimited chars for each row in file

    while (!(input_file.eof()))
    {
        std::getline(input_file, line); // Will use '\n' to delimit lines
        v.push_back(line);
    }
    input_file.close();
    return v;
}


std::vector<int> calcStatistics(const int months, const int days,
    const std::vector<std::string>& v) {

    std::vector<int> data; // To store total cumulatives, and largest num of rainy days

    int totalRainy{ 0 }, totalSunny{ 0 }, totalCloudy{ 0 },
        highestRain{ 0 };

    for (int row = 0; row < months; row++)
    {
        int monthRainy{ 0 }, monthSunny{ 0 }, monthCloudy{ 0 }; // Iteration of outer loop, these will represent the next month

        for (int col = 0; col < days; col++)
        {
            if (v[row][col] == 'R') {
                monthRainy += 1;
            }
            else if (v[row][col] == 'C') {
                monthCloudy += 1;
            }
            else { // Sunny
                monthSunny += 1;
            }
        } // End inner for
        data.push_back(monthRainy); // Per each month totals
        totalRainy += monthRainy;
        data.push_back(monthCloudy);
        totalCloudy += monthCloudy;
        data.push_back(monthSunny);
        totalSunny += monthSunny;

        if (monthRainy > highestRain) { // Initially will always be true if
            // month has at least one 'R' recorded
            highestRain = monthRainy;
            G_RAIN_PAIR.first = highestRain; // Int
            G_RAIN_PAIR.second = determineRowMonth(row);
        }

    } // End outer for

    data.push_back(totalRainy);
    data.push_back(totalCloudy);
    data.push_back(totalSunny);

    return data;
}


std::string determineRowMonth(const int row) {
    std::string rowMonth;

    switch (row)
    {
    case 0:
        rowMonth = "June";
        break;
    case 1:
        rowMonth = "July";
        break;
    case 2:
        rowMonth = "August";
        break;
    default:
        break;
    }
    return rowMonth;
}


void displayResults(const std::vector<int>& v, const int months) {
    // Show results
    std::cout << std::setfill('*') << std::setw(50) << std::setw(50) << '\n';
    std::cout << std::setfill(' ') << std::setw(30) << "WEATHER REPORT" << '\n';
    std::cout << std::setfill('*') << std::setw(50) << std::setw(50) << "\n\n";

    std::cout << "Month\tRainy Days\tCloudy Days\tSunny Days\n";
    std::cout << "---------------------------------------------------\n\n";
    std::cout << "June\t\t" << v[0] << "\t\t" << v[1] << "\t\t" << v[2] << '\n';
    std::cout << "July\t\t" << v[3] << "\t\t" << v[4] << "\t\t" << v[5] << '\n';
    std::cout << "August\t\t" << v[6] << "\t\t" << v[7] << "\t\t" << v[8] << '\n';

    std::cout << "\nTotal " << months << " month rainy days: " << v[9] << '\n';
    std::cout << "Total " << months << " month cloudy days: " << v[10] << '\n';
    std::cout << "Total " << months << " month sunny days: " << v[11] << "\n\n";

    std::cout << "Month with the most rain: " << G_RAIN_PAIR.second << '\n';
}
