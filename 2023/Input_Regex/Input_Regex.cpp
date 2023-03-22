//	Preset project templated to utilize W4 warning level, and use the C++20 
//  compiling standard

/*
    Comment code shortcut => CNTRL + K, CNTRL + C (Uncommment with CNTRL + K,
    CNTRL + U)

    .editorconfig will override any settings used in Options.

    Format code shortcut => CNTRL + K, CNTRL + D

*/

#include <input_regex.h>
#include <common_includes.h>

bool isValidEmail(const std::string_view s, const std::regex er);


int main() {
    bool proceed{ true };
    while (proceed)
    {
        std::string user_email{ };
        std::cout << "Enter your email address => ";
        // 'ws' arg ignores leading whitespace from a previous call to 'cin'
        //std::getline(std::cin >> std::ws, user_email);
        std::cin >> user_email;
        // Init a string_view variable, and implicitly convert user_email
        // Less expensive to pass this to function params
        std::string_view sv{ user_email };
        //int len{ static_cast<int>(user_email.length()) };
        //std::cout << "Length of provided arg:\t " << len << '\n';

        /*In C++ regex, backslashes MUST be escaped with another
        // backslash in order to preserve a literal - such as the case with
        the '.' */
        std::regex email_regex
        { "^[a-zA-Z0-9_.-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$" };

        bool result = isValidEmail(sv, email_regex);
        result ? std::cout <<
            "The provided email address " << user_email << " is VALID!\n" :
            std::cout << "The provided email address "
            << user_email << " is INVALID\n";
        char response{  };
        std::cout << "\n\nGo again? "; std::cin >> response;
        if ((response != 'y') && (response != 'Y')) {
            proceed = false;
        }
    }

    return 0;
}

