#ifndef STRATEGY_H
#define STRATEGY_H

#include <cstdint>
#include <iostream>

class Strategy {
  private:
    uint32_t m_Len;
    uint64_t m_Val;
    uint32_t m_Bcnt;
  public:
    Strategy(uint64_t val, const uint32_t & len);
    uint32_t length() const { return m_Len; }
    const uint64_t & val() const { return m_Val; }
    const uint32_t & bcnt() const { return m_Bcnt; }
    friend std::ostream & operator << (std::ostream & out, const Strategy & s);
};

#endif
