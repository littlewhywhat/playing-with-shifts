#ifndef RANDOM_H
#define RANDOM_H

#include <ctime>

class Random {
  private:
    unsigned m_Seed;
  public:
    Random() : m_Seed(std::time(0)); 
    uint32_t randint(const uint32_t & to) const;
    uint32_t randint(const uint32_t & from, const uint32_t & to) const;
    uint32_t randnode(const uint32_t & cnt_nodes) const;
    uint32_t randlbl() const;
    friend std::ostream & operator << (std::ostream & out, const Random & src);
};

#endif
