#ifndef MODE_H
#define MODE_H

#include "strategy.h"

class WordData;
class WordTable;

class Mode {
  public:
    virtual ~Mode() {};
    bool good_strat(const Strategy & s, const WordData & wd) const {
        throw "Non-compatible mode and worddata";
    }
    virtual bool good_strat(const Strategy & s, const WordTable & wt) const {
        throw "Non-compatible mode and worddata";
    }
};

#endif
