#ifndef MODE_H
#define MODE_H

#include <cstdint>

#include "strategy.h"
#include "wordtree.h"
#include "alphabet.h"

class Mode {
  public:
    virtual ~Mode() {};
    virtual bool good_strategy(Strategy & s, WordTree & wt, Alphabet & alpha) const = 0;
};

#endif
