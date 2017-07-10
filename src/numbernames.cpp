#include "numbernames.h"

std::string NumberNames::get_name(const std::string & prefix, int number) {
    std::string name = prefix;
    name.append(std::to_string(number));
    return name;
}
