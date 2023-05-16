/*
Write a program that uses a structure to store the following data:
Member      Description
Name        Student name
Idnum       Student ID number
Tests       Pointer to array of test scores
Average     Average test score
Grade       Course grade

The program should keep a list of test scores for a group of students.
It should ask the user how many test scores there are to be and how many
students there are. It should then dynamically allocate an array of structures.
Each structure’s Tests member should point to a dynamically allocated array that
will hold the test scores. After the arrays have been dynamically allocated,
the program should ask for the ID number and all the test scores for each student.
The average test score should be calculated and stored in the average member of each structure.
The course grade should be computed on the basis of the following grading scale:

Average Test Grade Course Grade
91–100 A
81–90 B
71–80 C
61–70 D
60 or below F

The course grade should then be stored in the Grade member of each structure.
Once all this data is calculated, a table should be displayed on the screen
listing each student’s name, ID number, average test score, and course grade.

Input Validation: Be sure all the data for each student is entered. Do not accept negative
numbers for any test score.
*/
#include "common_includes.h"

// Struct definition
struct Student
{
    std::string name;
    unsigned id_num;
    int* test_scores;
    float average;
    char course_grade;
};

// Global constants
constexpr int A_LOW{ 91 }, B_HIGH{ 90 }, B_LOW{ 81 }, C_HIGH{ 80 },
C_LOW{ 71 }, D_HIGH{ 70 }, D_LOW{ 61 };

// Forward decs
std::unique_ptr<Student[]> initStudent(const int, const int);

void validateScore(int&);

float calcAverage(int*, const int num_tests);

inline char determineLetterGrade(const float);


int main() {

    // Local vars for cin
    int num_students, num_tests;
    // Get user input - how many students and how many tests
    std::cout << "Please enter the number of students\n"
        << "And number of tests per student ['#students' '#tests']: ";
    std::cin >> num_students >> num_tests;

    auto students(initStudent(num_students, num_tests)); // Returns ptr to complete Student struct
    std::cout << "\n\n";
    for (int i = 0; i < num_students; i++)
    {
        std::cout << "STUDENT: " << students[i].name << '\n';
        std::cout << "ID NUMBER: " << students[i].id_num << '\n';
        std::cout << "TEST SCORES: ";
        for (int j = 0; j < num_tests; j++)
        {
            std::cout << students[i].test_scores[j] << ' ';
        }
        std::cout << std::fixed << std::setprecision(2)
            << "\nAVERAGE SCORE: " << students[i].average << '\n';
        std::cout << "COURSE GRADE: " << students[i].course_grade << "\n\n";
    }

    return 0;
}


std::unique_ptr<Student[]> initStudent(const int num_students, const int num_tests) {

    // Locs
    std::unique_ptr<Student[]> s(new Student[num_students]);
    int* s2 = nullptr;
    // get addl info from user
    for (int i = 0; i < num_students; i++)
    {
        s2 = new int[num_tests];
        ignoreExtraneous(); // after calling cin in main()
        std::cout << "Enter the name for student " << (i + 1) << ": ";
        std::getline(std::cin, s[i].name);
        std::cout << "And the ID number for " << s[i].name << ": ";
        std::cin >> s[i].id_num;

        for (int j = 0; j < num_tests; j++)
        {
            int curr_score;
            std::cout << "Enter test score " << (j + 1) << " for "
                << s[i].name << " => ";
            validateScore(curr_score);
            s2[j] = curr_score;
        } // end inner for

        // Calc average score per struct, since each represents 1 student
        float avg = calcAverage(s2, num_tests);
        s[i].test_scores = s2; // copy s2 values into member at end of out iteration
        s[i].average = avg;
        s[i].course_grade = determineLetterGrade(avg);
    } // end outer for

    return s;
}


void validateScore(int& user_input) {
    while (!(std::cin >> user_input) || user_input < 0)
    {
        std::cin.clear();
        ignoreExtraneous();
        std::cout << "ERROR: Score must NOT be negative!\n=> ";
    }

}


float calcAverage(int* t_arr, const int num_tests) {
    float total{ 0.0f };

    for (int i = 0; i < num_tests; i++)
    {
        total += *(t_arr + i);
    }

    return (total / num_tests);
}


inline char determineLetterGrade(const float avg) {
    float rounded = round(avg);
    
    if (rounded >= A_LOW)
    {
        return 'A';
    }
    else if (rounded >= B_LOW && rounded <= B_HIGH) {
        return 'B';
    }
    else if (rounded >= C_LOW && rounded <= C_HIGH) {

        return 'C';
    }
    else if (rounded >= D_LOW && rounded <= D_HIGH) {
        return 'D';
    }
    else {
        return 'F';
    }
}
