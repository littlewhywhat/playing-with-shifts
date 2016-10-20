#ifndef RANDOM_H
#define RANDOM_H

#include <ctime>
#include <cstdint>
#include <ostream>

class Random {
  private:
    unsigned m_Seed;
  public:
    Random(); 
    uint32_t randint(const uint32_t & to) const;
    uint32_t randint(const uint32_t & from, const uint32_t & to) const;
    uint32_t randnode(const uint32_t & cnt_nodes) const;
    uint32_t randlbl() const;
    friend std::ostream & operator << (std::ostream & out, const Random & src);
};

#endif
