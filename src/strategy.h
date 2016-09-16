#ifndef STRATEGY_H
#define STRATEGY_H

#include <vector>
#include <cstdint>

class Strategy {
  private:
    uint32_t m_Len;
    uint64_t m_Val;
    std::vector<uint32_t> m_BIds;
  public:
    Strategy(uint64_t val, uint32_t len) : m_Len(len), m_Val(val) {
        uint64_t mask = 1;
        for (uint32_t i = 0; i < len; i++) {
            if (val & mask)
                m_BIds.push_back(i);
            val >>= 1;
        }
    }
    const std::vector<uint32_t> bids() const {
        return m_BIds;
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
