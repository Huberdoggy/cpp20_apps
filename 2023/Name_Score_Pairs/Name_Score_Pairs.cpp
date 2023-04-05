/*
Write a program where you first enter a set of name-and-value pairs,
such as Joe 17 and Barbara 22. For each pair, add the name to a vector
called names and the number to a vector called scores
(in corresponding positions, so that if names[7]=="Joe" then scores[7]==17).
Terminate input with NoName 0. Check that each name is unique and terminate with
an error message if a name is entered twice.
Write out all the (name,score) pairs, one per line.

Modify the program from exercise 19 so that when you enter an integer,
the program will output all the names with that score or score not found.

Define a class Name_value that holds a string and a value. Rework this excercise
to use a vector<Name_value> instead of two vectors.
*/

#include "name_score_declarations.h"

bool checkUniqeNames(std::vector<std::string>& v) {
    // should I copy the array vs reference? For ease of associating scores
    // to names later?
    int count{ 0 };
    std::sort(v.begin(), v.end()); // alphabetic sort thru final index
    for (int i = 0; i < v.size(); i++)
    {
        if (i == 0) {
            continue; // Don't care - need at least 1 index to compare to
        }
        else if (v[i] == v[i - 1])
        {
            count++; // Name is dupe
        }
    }

    return (count > 0) ?
        throw std::runtime_error("Error, DUPLICATE name detected!") : true;
}


int getSelection(const int choice, std::vector<int>& scores_v,
    std::vector<std::string>& names_v_copy) {

    switch (choice)
    {
    case 1:
    {
        int score{ 0 };
        std::cout << "Enter desired score to search names => ";
        while (!(std::cin >> score))
        {
            std::cin.clear(); // Removes error state from buffer
            ignoreExtraneous(); // In .h file - ignore numeric limits up to nl
            std::cout << "INVALID ENTRY\n";
            std::cout << "=> ";
        }
        namesWithScore(score, scores_v, names_v_copy);
        break;
    }
    case 2:
        exit(EXIT_SUCCESS);
    default:
        std::cerr << "Unknown choice " << choice;
        exit(EXIT_FAILURE);
    }

    return 0;
}


inline bool printResult(const std::vector<std::string>& found)
{
    return (found.size() > 0) ? true : false;
}


void namesWithScore(const int score, std::vector<int>& scores_v,
    std::vector<std::string>& names_v_copy) {

    std::vector<std::string> found{};
    for (int i = 0; i < names_v_copy.size(); i++)
    {
        for (int j = 0; j < scores_v.size(); j++) // For each iteration of i,
            // iterate scores completely
        {
            if (i == j && scores_v[j] == score)
            {
                found.push_back(names_v_copy[i]);
            }
        }
    }

    if (!printResult(found)) {
        std::cout << "SCORE " << score << " NOT FOUND";
        return;
    }
    // Default
    for (auto& i : found)
    {
        std::cout << i << " has a score of " << score << '\n';
    }
}


int main() {
    // Init variables to store a name and a score from input
    std::string name{};
    int score{ 0 };
    std::vector<std::string> names_v{}; // Init vec to store names
    std::vector<std::string> names_v_copy{}; // To hold identical names 
    // unsorted for later
    std::vector<int> scores_v{}; // Init vect to store scores
    // Get user input in value pairs until termination detected => NoName 0
    while (std::cin)
    {
        std::cout <<
            "Enter a name followed by a score\n(Type 'NoName 0' to quit): ";
        std::cin >> name >> score;
        if (name == "NoName" && score == 0) break;

        names_v.push_back(name);
        names_v_copy.push_back(name);
        scores_v.push_back(score);

    }

    try
    {
        // Check for unique names against entire names vector
        if (names_v.size() > 0) // We didn't just immediately end the program
        {
            if (checkUniqeNames(names_v))
            {
                int choice{ 0 };
                std::cout << "All names are unique!\n\n";
                std::cout << "Please choose from the following:\n\n";
                std::cout << "\t1) Lookup all names that have SCORE\n";
                std::cout << "\t2) Quit\n";
                std::cout << "=> ";
                std::cin >> choice;
                getSelection(choice, scores_v, names_v_copy); // Pass unsorted
                return 0;
            }
        }

    }
    catch (const std::exception& e)
    {
        std::cout << "Exception occured " << e.what() << '\n';
        return 1;
    }
    return 0;
}

