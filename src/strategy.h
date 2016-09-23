#ifndef STRATEGY_H
#define STRATEGY_H

#include <cstdint>

class Strategy {
  private:
    uint32_t m_Len;
    uint64_t m_Val;
    uint32_t m_Bcnt;
  public:
    Strategy(uint64_t val, const uint32_t & len) : m_Len(len), m_Val(val), m_Bcnt(0) {
        while (val) {
            if (val & 1)
                m_Bcnt++;
            val >>= 1;
        }
    }
    const uint64_t & val() const {
        return m_Val;
    }
    const uint32_t & Bcnt() const {
        return m_Bcnt;
    }
    friend std::ostream & operator << (std::ostream & out, const Strategy & s) {
        uint64_t mask = 1;
        uint64_t val = s.m_Val;
        for (uint32_t i = 0; i < s.m_Len; i++) {
            out << (val & mask);
            val >>= 1;
        }
        return out;
    }
};

#endif
