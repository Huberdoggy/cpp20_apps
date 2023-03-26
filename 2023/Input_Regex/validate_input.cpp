#include <common_includes.h>

bool isValidEmail(const std::string_view s, const std::regex er) {
    return std::regex_match(static_cast<std::string>(s), er) ? true : false;
    // Don't return a 'string_view' from func. Bad practice
}