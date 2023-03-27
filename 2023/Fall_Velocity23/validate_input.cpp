#include "height_calc.h"

bool validateInput(const std::string u_imp, const std::regex re) {
    return (std::regex_match(u_imp, re)) ? 1 : 0;
}