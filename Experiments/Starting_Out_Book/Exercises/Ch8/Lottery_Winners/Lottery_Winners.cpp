/*
A lottery ticket buyer purchases 10 tickets a week, always playing the same
10 5-digit �lucky� combinations. Write a program that initializes an array
or a vector with these numbers and then lets the player enter this week�s
winning 5-digit number. The program should perform a linear search through the
list of the player�s numbers and report whether or not one of the tickets is a
winner this week.
*/

#include "common_includes.h"
#include <random> // For larger generator capability than RAND_MAX

inline bool testExistence(const std::ifstream& input_file);
void genRandTicket(std::ofstream& output_file, const int combos, std::mt19937& random_engine);
void buildVec(std::vector<std::string>& lot_nums, std::ifstream& input_file);
int verifyUserInput(int& user_input, const std::regex num_digits,
    const std::string_view err_msg);

bool searchWinner(const std::vector<std::string>& lot_nums, int chosen_num);


int main() {

    // Local constants
    constexpr int COMBINATIONS{ 10 };
    const std::regex NUM_DIGITS{ "^\\d{5}$" };
    const std::string err_msg = "ERROR. Input must be an integer of exactly 5 digits";

    // Build stream file path from env
    std::string filePath = std::getenv("STREAMFILE_DIR");
    filePath += "\\WinningNums.txt";

    // Build vector from input file read
    std::vector<std::string> lotNums(COMBINATIONS);
    std::ofstream output_file(filePath);

    std::random_device random_device; // Gen from hardware
    std::mt19937 random_engine(random_device()); // Seed the generator once per program run
   
    genRandTicket(output_file, COMBINATIONS, random_engine);
    std::ifstream input_file(filePath); // Use same file for input after closing in prev function call

    // Ensure source file is intact after writing
    if (!(testExistence(input_file))) {
        std::cout << "Error accessing file.\n";
        return 1;

    }

    buildVec(lotNums, input_file); // Pass refs
    for (auto& i : lotNums)
    {
        std::cout << i << ' '; // Testing...
    }

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


void genRandTicket(std::ofstream& output_file, const int combos,
    std::mt19937& random_engine) {

    unsigned random; // Will hold value I generate betwenn 13 and 99k each
    // of the 10 iterations
    std::uniform_int_distribution<unsigned> dist_13k_99k(13000, 99000);
    // Using the uniform distribution for a more equal spread
    for (int i = 0; i < combos; i++)
    {
        random = dist_13k_99k(random_engine);
        output_file << random << std::endl;
    }

    output_file.close();
}


void buildVec(std::vector<std::string>& lot_nums, std::ifstream& input_file) {

    lot_nums.clear();
    std::string line;

    while (!(input_file.eof()))
    {
        std::getline(input_file, line);
        // std::getline(input_file, line, ' '); // can use delimiter arg
        lot_nums.push_back(line);
    }

    std::sort(lot_nums.begin(), lot_nums.end()); // Modify ref input vec
    input_file.close();
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
