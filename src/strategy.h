#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>

class Strategy {
  private:
    uint32_t m_Val;
    uint32_t m_Lim;
  public:
    Strategy(uint32_t val, uint32_t lim) : m_Val(val), m_Lim(lim) {}
    void incr() { m_Val++; }
    uint32_t countB() {
        uint32_t val = m_Val;
        uint32_t i = 0;
        while (val != 0) {
            if (val % 2 != 0)
                i++;
            val /= 2;
        }
        return i;
    }
    bool hasPrevB(uint32_t pos) const {
        for (int i = (int)pos; i >= 0; i--)
            if (at(i))
                return true;
        return false;
    }
    bool hasNextB(uint32_t pos) const {
        for (uint32_t i = pos; i < m_Lim; i++)
            if (at(i))
                return true;
        return false;
    }
    char at(uint32_t pos) const {
        uint32_t val = m_Val;
        val >>= pos;
        return val % 2;

    }
    uint32_t lim() const {
        return m_Lim;
    }
    friend std::ostream & operator << (std::ostream & out, const Strategy & src) {
        uint32_t val = src.m_Val;
        uint32_t lim = src.m_Lim;
        //out << val << std::endl;
        while (lim > 0) {
            lim--;
            out << val % 2;
            val >>= 1;
        }
       return out; 
    }
};

#endif
