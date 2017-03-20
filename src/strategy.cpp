#include <cstdint>
#include <iostream>

#include "strategy.h"

Strategy::Strategy(uint64_t val, const uint32_t & len) : m_Len(len), m_Val(val), m_Bcnt(0) {
    cntBs();
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

Strategy Strategy::MAX(const uint32_t &len) {
    if (len == 0)
        return MIN(len);
    if (len > 63) {
        //TODO check if length = 64 preserve other operations
        Strategy max((uint64_t) (-1), 64);
        return MAX((uint64_t) (-1));
    }
    Strategy max((uint64_t) ((1 << len) - 1), len);
    return max;
}

Strategy Strategy::MIN(const uint32_t &len) {
    Strategy min(0, len);
    return min;
}

void Strategy::cntBs() {
    m_Bcnt = 0;
    uint64_t val = m_Val;
    while (val) {
        if (val & 1)
            m_Bcnt++;
        val >>= 1;
    }
}

void Strategy::increment() {
    m_Val++;
    cntBs();
}
