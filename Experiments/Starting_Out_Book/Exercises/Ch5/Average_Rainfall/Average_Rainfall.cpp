/*
Average Rainfall
Write a program that uses nested loops to collect data and calculate the
average rainfall over a period of years. The program should first ask for the
number of years. The outer loop will iterate once for each year.
The inner loop will iterate twelve times, once for each month.
Each iteration of the inner loop will ask the user for the inches of rainfall
for that month. After all iterations, the program should display the number
of months, the total inches of rainfall, and the average rainfall per month
for the entire period.

Input Validation: Do not accept a number less than 1 for the number of years.
Do not accept negative numbers for the monthly rainfall.
*/

# include "common_includes.h"

// Global constants
constexpr int MIN_NUM_YEARS{ 1 };
constexpr int MONTHS{ 12 }, BEGIN_MONTH{ 1 };
// Init array to map loop var to str representation of month
const std::vector<std::string> STR_MONTHS{ "January", "February", "March",
"April", "May", "June", "July", "August", "September", "October", "November",
"December" };

bool verifyInputMinimums(int& user_input, const int min_required,
    std::string_view err_msg) {

    while (user_input < min_required)
    {
        std::cout << err_msg << "\n=> ";
        std::cin >> user_input; // Pass by ref will preserve new value
    }
    return true; // Default once 'while' condition is false
}

inline std::string monthAsStr(int loop_var) {
    // To offset the zero index
    return STR_MONTHS[loop_var - 1];
}

inline bool verifyRainfall(float rain_this_period) {
    return (rain_this_period < 0.0) ? 0 : 1;
}


void displayMetrics(int &total_months, float &total_rainfall) {
    std::cout << "\n\n";
    std::cout << std::setfill('*') << std::setw(30) << "\n";
    std::cout << std::setfill(' ') << std::setw(22) << "RAINFALL PERIOD METRICS\n";
    std::cout << std::setfill('*') << std::setw(30) << "\n\n";
    std::cout << std::setfill(' ') << "Total Months: " << total_months << "\n";
    std::cout << std::fixed << std::setprecision(2) << 
        "Total Rainfall: " << total_rainfall << " in.\n";
    std::cout << "Average Rainfall Per Month: " <<  
        (total_rainfall / total_months) << " in." << "\n";
}


int main() {
    // Init var for years, total months, and total rainfall
    int years, total_months{ 0 };
    float total_rainfall{ 0.0f };
    // Init vars to pass as string view for error msgs
    std::string years_err_msg = "ERROR - 'Years' requires an integer of " +
        std::to_string(MIN_NUM_YEARS) + " or greater";
    // Get user input for years
    std::cout << "Enter the desired number of years to" <<
        " inspect precipitation data for: ";
    std::cin >> years;
    verifyInputMinimums(years, MIN_NUM_YEARS, years_err_msg);
    // Once good, calculate the value for total_months for later
    total_months = years * MONTHS;

    // Begin nested for loop
    for (int i = MIN_NUM_YEARS; i <= years; i++)
    {
        for (int j = BEGIN_MONTH; j <= MONTHS; j++)
        {
            // Init temp for user input, to be added to total_rainfall
            float rain_this_period{ 0.0f };
            std::cout << "How many inches of rainfall for " <<
                monthAsStr(j) << " of year " << i << "?\n=> ";
            std::cin >> rain_this_period;
            // Verify the supplied above is not negative
            while (!(verifyRainfall(rain_this_period))) {
                std::cout << "ERROR - Please ensure input is non-negative\n" << 
                    "Try again => ";
                std::cin >> rain_this_period;
            }
            // Increment total tracking vars
            total_rainfall += rain_this_period;
            
        }
    } // end nested for
   
    displayMetrics(total_months, total_rainfall);

    return 0;
}

