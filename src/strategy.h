#ifndef STRATEGY_H
#define STRATEGY_H

#include <cstdint>
#include <iostream>

/*
 *  Holds a value of binary strategy.
 *  Can be incremented and copied.
 */
class Strategy {
  private:
    uint32_t m_Len;
    uint64_t m_Val;
    uint32_t m_Bcnt;
    void copy(const Strategy & src) {
        m_Len = src.m_Len;
        m_Val = src.m_Val;
        m_Bcnt = src.m_Bcnt;
    }
    void cntBs();
  public:
    Strategy(uint64_t val, const uint32_t & len);
    Strategy(const Strategy & src) {
        copy(src);
    }
    Strategy& operator = (const Strategy & src) {
        if (this != &src)
            copy(src);
        return *this;
    }
    uint32_t length() const { return m_Len; }
    const uint64_t & val() const { return m_Val; }
    const uint32_t & bcnt() const { return m_Bcnt; }
    void increment();
    friend std::ostream & operator << (std::ostream & out, const Strategy & s);
    static Strategy MAX(const uint32_t & len);
    static Strategy MIN(const uint32_t & len);
};

#endif
