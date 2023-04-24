/*
Write a program that lets the user play the game of Rock, Paper, Scissors
against the computer. The program should work as follows.

1. When the program begins, a random number in the range of 1 through 3 is
generated. If the number is 1, then the computer has chosen rock.
If the number is 2, then the computer has chosen paper. If the number is 3,
then the computer has chosen scissors. (Don’t display the computer’s choice yet.)

2. The user enters his or her choice of “rock”, “paper”, or “scissors” at the keyboard.
(You can use a menu if you prefer.)

3. The computer’s choice is displayed.

4. A winner is selected according to the following rules:

If one player chooses rock and the other player chooses scissors, then rock wins.
(The rock smashes the scissors.)
If one player chooses scissors and the other player chooses paper, then scissors
wins. (Scissors cuts paper.)
If one player chooses paper and the other player chooses rock, then paper wins.
(Paper wraps rock.)
If both players make the same choice, the game must be played again to determine
the winner
*/

#include "common_includes.h"
// Global constants for valid choices - avoiding 'magic numbers'
constexpr unsigned NUM_ROCK{ 1 };
constexpr unsigned NUM_PAPER{ 2 };
constexpr unsigned NUM_SCISSORS{ 3 };

const std::string STR_ROCK = "Rock";
const std::string STR_PAPER = "Paper";
const std::string STR_SCISSORS = "Scissors";

const std::string USER_WINS = "YOU";
const std::string PC_WINS = "PC";
const std::string TIE = "Tie";

// Forward func declarations
void displayMenu();
std::string mapIntToStr(unsigned short num_choice);
std::string determineWinner(const std::string_view str_user_choice, 
    const std::string_view str_pc_choice);
inline bool announceVictor(bool& flag, const std::string_view victor);

int main() {
    bool repeat{ 1 }; // Default flag to continue game for ties
    // First, create a time stamp for seed, to ensure values differ each time
    // prog runs
    while (repeat)
    {
        srand(static_cast<unsigned>(time(NULL)));
        // Generate a random number in the range 1 to 3
        // Syntax: offset + (rand() % range); 'Range' excludes high limit
        unsigned short random = 1 + (rand() % 3);
        // Pass rand to function to map into to string (rock, paper, or scissors)
        // Store it, but don't display yet...
        std::string str_pc_choice = mapIntToStr(random);
        // Now, show opts, and get user input - their choice
        displayMenu();
        unsigned short num_choice{ 0 };
        while (!(num_choice > 0 && num_choice <= NUM_SCISSORS))
        {
            std::cout << "\nMake Choice => ";
            std::cin >> num_choice;

        }
        // Re-assign user-choice to str mapping for consistency
        std::string str_user_choice = mapIntToStr(num_choice);
        // After valid input, allow them to see PC's choice
        std::cout << "\nTHE PC HAS CHOSEN: " << str_pc_choice << '\n';
        std::cout << "YOU HAVE CHOSEN: " << str_user_choice << '\n';
        // Get the value for tie or winner
        std::string victor = determineWinner(str_user_choice, str_pc_choice);
        bool goAgain = announceVictor(repeat, victor);
            goAgain ? // If returns true, flag is still set, tiebreaker must be played
            printf("Another round will be needed for the tie-breaker\n\n") :
            printf("The winner is: %s\n\n", victor.c_str());
    }

    return 0;
}

void displayMenu() {
    std::cout << "Please choose from the following [1, 2, or 3]:\n\n";
    std::cout << "\t1)\tRock\n";
    std::cout << "\t2)\tPaper\n";
    std::cout << "\t3)\tScissors\n";
}


std::string mapIntToStr(unsigned short num_choice) {
    std::string choice;
    switch (num_choice)
    {
    case NUM_ROCK:
        choice = STR_ROCK;
        break;
    case NUM_PAPER:
        choice = STR_PAPER;
        break;
    case NUM_SCISSORS:
        choice = STR_SCISSORS;
        break;
    default:
        break;
    }
    return choice;
}

std::string determineWinner(const std::string_view str_user_choice, 
    const std::string_view str_pc_choice) {
    // Rock crushes scissors
    if (str_user_choice == STR_ROCK && str_pc_choice == STR_SCISSORS)
    {
        return USER_WINS;
    }
    else if (str_pc_choice == STR_ROCK && str_user_choice == STR_SCISSORS)
    {
        return PC_WINS;
    }
    // Paper cuts scissors
    else if (str_pc_choice == STR_SCISSORS && str_user_choice == STR_PAPER)
    {
        return PC_WINS;
    }
    else if
        (str_pc_choice == STR_PAPER && str_user_choice == STR_SCISSORS)
    {
        return USER_WINS;
    }
    // Paper covers rock
    else if (str_pc_choice == STR_PAPER && str_user_choice == STR_ROCK)
    {
        return PC_WINS;
    }
    else if
        (str_pc_choice == STR_ROCK && str_user_choice == STR_PAPER)
    {
        return USER_WINS;
    }
    // Handle tie
    else if (str_user_choice == str_pc_choice || str_pc_choice == str_user_choice) {
        return TIE;
    }

}

inline bool announceVictor(bool& repeat, const std::string_view victor) {
    return (victor != TIE) ? repeat = 0 : repeat;
}