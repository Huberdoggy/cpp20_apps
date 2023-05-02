/*
A lottery ticket buyer purchases 10 tickets a week, always playing the same
10 5-digit “lucky” combinations. Write a program that initializes an array
or a vector with these numbers and then lets the player enter this week’s
winning 5-digit number. The program should perform a linear search through the
list of the player’s numbers and report whether or not one of the tickets is a
winner this week. Here are the numbers:

13579 26791 26792 33445 55555
62483 77777 79422 85647 93121

Modify the program you wrote so it
performs a binary search instead of a linear search.

*/

#include "common_includes.h"


inline bool testExistence(const std::ifstream& input_file);
void buildVec(std::vector<std::string>& lot_nums, std::ifstream& input_file);
int verifyUserInput(int& user_input, const std::regex num_digits,
    const std::string_view err_msg);

bool searchWinner(const std::vector<std::string>& lot_nums, int chosen_num);


int main() {

    // Local constants
    constexpr int COMBINATIONS{ 10 };
    const std::regex NUM_DIGITS{ "^\\d{5}$" };
    const std::string err_msg = "ERROR. Input must be an integer of exactly 5 digits";

    // Build vector from input file read
    std::vector<std::string> lotNums(COMBINATIONS);
    std::ifstream input_file("NumberPicks.txt");

    // Ensure source file is intact
    if (!(testExistence(input_file))) {
        std::cout << "Error opening input file.\n";
        return 1;

    }
    buildVec(lotNums, input_file); // Pass refs
    /* for (auto & i : lotNums)
     {
         std::cout << i << ' '; // Testing...
     }*/

     // Get user input for this week's winning num
    int chosenNum;
    std::cout << "\nEnter this week's winning number => ";
    verifyUserInput(chosenNum, NUM_DIGITS, err_msg);
    (searchWinner(lotNums, chosenNum)) ?
        std::cout << "\nNumber " << chosenNum << " is a WINNER!\n" :
        std::cout << "\nSorry " << chosenNum
        << " wasn't among the winning numbers this week\n";
    return 0;
}


inline bool testExistence(const std::ifstream& input_file) {
    return (!input_file) ? false : true;
}


void buildVec(std::vector<std::string>& lot_nums, std::ifstream& input_file) {

    lot_nums.clear();
    std::string line;

    while (!(input_file.eof()))
    {
        std::getline(input_file, line, ' ');
        lot_nums.push_back(line);
    }

    std::sort(lot_nums.begin(), lot_nums.end()); // Modify ref input vec
}



int verifyUserInput(int& user_input, const std::regex num_digits,
    const std::string_view err_msg) {

    while (!(std::cin >> user_input) || !(std::regex_match(std::to_string(user_input), num_digits)))
    {
        std::cin.clear(); // Since condition set for !cin, this will clear flag
        // on incorrect data type entries
        ignoreExtraneous(); // And this will clear buffer up to new line
        std::cout << err_msg << "\n=> ";
    }
    return user_input; // Return reference to cin input
}


bool searchWinner(const std::vector<std::string>& lot_nums, int chosen_num) {
    for (int i = 0; i < lot_nums.size(); i++)
    {
        if (lot_nums[i] == std::to_string(chosen_num)) {
            return true;
        }
    } // end for

    return false; // chosen num is not a winner

}
