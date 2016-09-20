#ifndef MODE_H
#define MODE_H

#include "strategy.h"
#include "wordtable.h"

class Mode {
  public:
    virtual ~Mode() {};
    virtual bool good_strat(const Strategy & s, WordTable & wt) const = 0;     
};

#endif
