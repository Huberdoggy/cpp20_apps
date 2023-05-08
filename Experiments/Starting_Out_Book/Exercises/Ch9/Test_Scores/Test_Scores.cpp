/*
Write a program that dynamically allocates an array large enough to hold a
user defined number of test scores. Once all the scores are entered, the array
should be passed to a function that sorts them in ascending order. Another
function should be called that calculates the average score. The program should
display the sorted list of scores and averages with appropriate headings.
Use pointer notation rather than array notation whenever possible. Do not accept
negative numbers for test scores.


Modify the program above to allow the user to enter name-score
pairs. For each student taking a test, the user types the student’s name
followed by the student’s integer test score. Modify the sorting function so it
takes an array holding the student names and an array holding the student test
scores. When the sorted list of scores is displayed, each student’s name should
be displayed along with his or her score. In stepping through the arrays,
use pointers rather than array subscripts.
*/

#include "common_includes.h"

void getInputData(const short amount, std::string_view err_msg,
    short* test_scores, std::string* student_names);

short validateInput(short& num, std::string_view err_msg);

void sortScores(short* test_scores, std::string* student_names, const short amount);

double displayAvgScore(const short* test_scores, const short amount);

// Global constants
constexpr short MIN_REQUIRED{ 0 };


int main() {

    // Init pointers for (dynamic allocation size) array of student test scores
    // and names. String for err_msg
    std::string err_msg = "ERROR! Input must not be less than " +
        std::to_string(MIN_REQUIRED);
    std::string* student_names = nullptr;
    short* test_scores = nullptr, amount;
    char again;

    do
    {
        // Get user input - number of test scores/student names
        std::cout << "How many students do you wish to process" <<
            " test scores for? => ";
        validateInput(amount, err_msg);

        test_scores = new short[amount]; // Allocate size to that amount
        student_names = new std::string[amount];
        // Get name/score pairs from user
        getInputData(amount, err_msg, test_scores, student_names);
        sortScores(test_scores, student_names, amount);
        // Check what we got in the arrays
        std::cout << "Sorted names with associated scores in ascending order:\n";

        for (int i = 0; i < amount; i++)
        {
            std::cout << *(student_names + i) << std::setw(10);
        }

        //// Use null char to reset width
        std::cout << std::setfill('\0') << std::endl;

        //// Intentional seperation of all array indexes on a line

        for (int i = 0; i < amount; i++)
        {
            std::cout << *(test_scores + i) << std::setfill(' ') << std::setw(10);
        }

        std::cout << std::fixed
            << std::setprecision(2) << "\n\nRounded average of all supplied test scores: "
            << displayAvgScore(test_scores, amount) << std::endl;

        // Destroy objects created with new to release memory
        // Assign them back to nullptrs
        delete[] test_scores;
        delete[] student_names;
        test_scores = nullptr;
        student_names = nullptr;
        std::cout << "New input? => "; std::cin >> again;
        while (toupper(again) != 'Y' && toupper(again) != 'N') {
            std::cout << "Valid responses are 'Y' or 'N'\n=> ";
            std::cin >> again;
        }
    } while (toupper(again) == 'Y');
    return 0;
}


void getInputData(const short amount, std::string_view err_msg,
    short* test_scores, std::string* student_names) {

    // Local vars to hold input student names and scores
    short score{ 1 }; // Ensure initiliazed val > MIN_SCORE_REQUIRED for 
    // while condition doesn't execute false path the first time 
    std::string name;

    for (int i = 0; i < amount; i++)
    {
        std::cout << "Enter the name of student " << (i + 1) << " => ";
        std::cin >> name;
        std::cout << "Test score for student " << (i + 1) << " => ";
        validateInput(score, err_msg);
        // Map the input values to their respective arrays
        *(test_scores + i) = score; // Dereference point and assign score to that index (equiv to test_scores[i] = score)
        // Basicially, test_scores + index * sizeof(short) => Increments the offset in memory for each value
        *(student_names + i) = name;
    } // end for
}


short validateInput(short& num, std::string_view err_msg) {
    while (!(std::cin >> num) || num < MIN_REQUIRED) {
        std::cin.clear(); // Since condition set for !cin, this will clear flag
        // on incorrect data type entries
        ignoreExtraneous(); // And this will clear buffer up to new line
        std::cout << err_msg << "\n=> ";
    } // end while
    return num;
}


void sortScores(short* test_scores, std::string* student_names,
    const short amount) {

    int startScan, minIndex;
    short minElem;
    std::string swapStr;

    for (startScan = 0; startScan < (amount - 1); startScan++) // Outer loop stops at 2nd to last index
        // So that nested loop can compare +1 index to outer val
    {
        minIndex = startScan;
        minElem = *(test_scores + startScan); // Initially, deref assigns lowest to first index
        swapStr = *(student_names + startScan);
        for (int index = (startScan + 1); index < amount; index++)
        {
            if (*(test_scores + index) < minElem) // Pointer deref syntax of curr index value comparison
            {
                minElem = test_scores[index]; // Point to new lowest 
                swapStr = student_names[index]; // Assign corresponding index of names array
                minIndex = index;
            }
        } // end inner for

        // Swap => First, move old lowest to the right 
        *(test_scores + minIndex) = *(test_scores + startScan);
        *(student_names + minIndex) = *(student_names + startScan);
        // And move new lowest to the left - in the pos of the previous lowest
        *(test_scores + startScan) = minElem;
        *(student_names + startScan) = swapStr;
        // Before next full iteration...
    } // end outer for

}


double displayAvgScore(const short* test_scores, const short amount) {

    double total{ 0.0 }; // Init local var to hold avg

    for (int i = 0; i < amount; i++)
    {
        total += *(test_scores + i);
    }

    return (total / amount);
}