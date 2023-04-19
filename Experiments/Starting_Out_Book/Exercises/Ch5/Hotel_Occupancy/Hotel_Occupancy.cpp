/*
Hotel Occupancy
Write a program that calculates the occupancy rate for a hotel.
The program should start by asking the user how many floors the hotel has.
A loop should then iterate once for each floor. In each iteration, the loop
should ask the user for the number of rooms on the floor and how many of them
are occupied. After all the iterations, the program should display how many
rooms the hotel has, how many of them are occupied, how many are unoccupied,
and the percentage of rooms that are occupied. The percentage may be calculated
by dividing the number of rooms occupied by the number of rooms.
NOTE: It is traditional that most hotels do not have a thirteenth floor.
The loop in this program should skip the entire thirteenth iteration.

Do not accept a value less than 1 for the number of floors. Do not
accept a number less than 10 for the number of rooms on a floor.
*/

#include "common_includes.h"

// GLOBAL CONSTANTS - Per instructions
constexpr int MIN_FLOORS{ 1 };
constexpr int MIN_ROOMS{ 10 };
constexpr int SKIP_FLOOR{ 13 };

inline float calcPercentOccupied(int occupied, 
    int total_rooms) {

    return 
        (static_cast<float>(occupied) / static_cast<float>(total_rooms)) * 100;
}

bool verifyInputMinimums(int& user_input, const int min_required,
    std::string_view err_msg) {

    while (user_input < min_required)
    {
        std::cout << err_msg << "\n=> ";
        std::cin >> user_input;
    }
    return true;
}


int main() {

    int occupied{ 0 }, total_rooms{ 0 }; // Eventual determination afer loop completes

    // String messages
    std::string floor_msg = "ERROR - Hotel must have at least " +
        std::to_string(MIN_FLOORS) + " floor";
    std::string room_msg = "ERROR - Floor must have at least " +
        std::to_string(MIN_ROOMS) + " rooms";

    // Get input from user
    std::cout << "How many floors does the hotel have? => ";
    // Init variables for user input num_floors
    int num_floors;
    std::cin >> num_floors;
    verifyInputMinimums(num_floors, MIN_FLOORS, floor_msg);

    for (int i = MIN_FLOORS; i <= num_floors; i++)
    {
        if (i == SKIP_FLOOR)
        {
            continue; // Traditional not to have 13th floor
        }
        // Otherwise, init var to hold num_rooms within the block
        // as well as temp for occupied
        int num_rooms, num_occ;
        std::cout << "\n\nHow many rooms are on floor " << i << "? => ";
        std::cin >> num_rooms;
        verifyInputMinimums(num_rooms, MIN_ROOMS, room_msg);

        std::cout << "\nAnd how many are occupied? => ";
        std::cin >> num_occ;
        while (num_occ > num_rooms)
        {
            std::cout <<
                "ERROR - Impossible to have more occupied than rooms on floor "
                << i << "\n=> ";
            std::cin >> num_occ;
        }

        occupied += num_occ;
        total_rooms += num_rooms;
    }

    // Display metrics
    std::cout << "\n\n";
    std::cout << std::setfill('*') << std::setw(30) << "\n";
    std::cout << std::setfill(' ') << std::setw(22) << "HOTEL INFORMATION\n";
    std::cout << std::setfill('*') << std::setw(30) << "\n\n";
    std::cout << std::setfill(' ') << "Total Rooms: " << total_rooms << "\n";
    std::cout << "Total Occupied: " << occupied << "\n";
    std::cout << "Total Unoccupied: " << (total_rooms - occupied) << "\n";
    std::cout << std::fixed << std::setprecision(2) << "Percent Occupied: " 
        << calcPercentOccupied(occupied, total_rooms) << "%\n";

    return 0;
}

