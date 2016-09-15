#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>

class Strategy {
  private:
    uint64_t m_Init;
    uint64_t m_Val;
    uint64_t m_Lim;
  public:
    Strategy(uint64_t val, uint64_t lim) : m_Init(val), m_Val(val), m_Lim(lim) {}
    void incr() { m_Val++; }
    void decr() { m_Val--; }
    uint64_t countB() {
        uint64_t val = m_Val;
        uint64_t i = 0;
        while (val != 0) {
            if ((val & 1) != 0)
                i++;
            val >>= 1;
        }
        return i;
    }
    bool hasPrevB(uint64_t pos) const {
        for (int i = (int)pos; i >= 0; i--)
            if (at(i))
                return true;
        return false;
    }
    bool hasNextB(uint64_t pos) const {
        for (uint64_t i = pos; i < m_Lim; i++)
            if (at(i))
                return true;
        return false;
    }
    char at(uint64_t pos) const {
        uint64_t val = m_Val;
        val >>= pos;
        return val & 1;

    }
    uint64_t lim() const {
        return m_Lim;
    }
    bool outOfLen() const {
        uint64_t one = 1;
        return m_Val >= (one << m_Lim);
    }
    bool isZero() const {
        return !m_Val;
    }
    void reset() {
        m_Val = m_Init; 
    }
    friend std::ostream & operator << (std::ostream & out, const Strategy & src) {
        uint64_t val = src.m_Val;
        uint64_t lim = src.m_Lim;
        //out << val << std::endl;
        while (lim > 0) {
            lim--;
            out << (val & 1);
            val >>= 1;
        }
       return out; 
    }
};

#endif
