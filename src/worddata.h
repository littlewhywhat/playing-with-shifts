#ifndef WORDDATA_H
#define WORDDATA_H

#include <string>

#include "strategy.h"
#include "mode.h"

class WordData {
  public:
    virtual ~WordData() {}
    virtual void add(const std::string & word) = 0;
    virtual bool good_strat(const Strategy & s, const Mode & mode) const = 0;
    virtual std::ostream & print(std::ostream & out) const = 0;
    friend std::ostream & operator << (std::ostream & out, const WordData & src) {
        return src.print(out);
    }
};
#endif
