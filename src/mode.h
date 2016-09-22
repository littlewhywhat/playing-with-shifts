#ifndef MODE_H
#define MODE_H

#include "strategy.h"
#include "wordtable.h"

class Mode {
  protected:
    class Less {
      private:
        uint64_t m_Mask;
      public:
        Less(const uint64_t & mask) : m_Mask(mask) {}
        bool operator() (const uint64_t & a, const uint64_t & b) const {
            return (a & m_Mask) < (b & m_Mask);
        }
    };
  public:
    virtual ~Mode() {};
    virtual bool good_strat(const Strategy & s, const WordTable & wt) const = 0;     
};

#endif
