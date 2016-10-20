#include <cstdint>
#include <iostream>

#include "strategy.h"

Strategy::Strategy(uint64_t val, const uint32_t & len) : m_Len(len), m_Val(val), m_Bcnt(0) {
    while (val) {
        if (val & 1)
            m_Bcnt++;
        val >>= 1;
    }
}
std::ostream & operator << (std::ostream & out, const Strategy & s) {
    uint64_t mask = 1;
    uint64_t val = s.m_Val;
    for (uint32_t i = 0; i < s.m_Len; i++) {
        out << (val & mask);
        val >>= 1;
    }
    return out;
}
