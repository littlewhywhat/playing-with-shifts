#include <ctime>

#include "random.h"

Random::Random() : m_Seed(std::time(0)) {
    std::srand(m_Seed);
}

uint32_t Random::randint(const uint32_t & to) const {
    if (!to)
        throw "Division by zero error!";
    return std::rand() % to;
}

uint32_t Random::randint(const uint32_t & from, const uint32_t & to) const {
    if (from == to)
        return from;
    return randint(to - from) + from;
}

uint32_t Random::randnode(const uint32_t & cnt_nodes) const {
    return randint(cnt_nodes);
}

uint32_t Random::randlbl() const {
    return randint(2);
}

std::ostream & operator << (std::ostream & out, const Random & src) {
    out << src.m_Seed;
    return out;
}
