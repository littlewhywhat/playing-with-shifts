#ifndef WORDDATA_H
#define WORDDATA_H

#include <string>
#include <cstdint>

#include "strategy.h"
#include "mode.h"

class WordData {
  public:
    virtual ~WordData() {}
    virtual void add(const std::string & word) = 0;
    virtual void set_wd(Mode & mode) const = 0;
    virtual std::ostream & print(std::ostream & out) const = 0;
    friend std::ostream & operator << (std::ostream & out, const WordData & src) {
        return src.print(out);
    }
};
#endif
