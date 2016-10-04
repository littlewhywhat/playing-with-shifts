#ifndef MODE_H
#define MODE_H

#include "strategy.h"

class WordData;
class WordTable;
class WordTree;

class Mode {
  protected:
    virtual bool has_wd() const = 0;
    virtual bool good_strat_ch(const Strategy & s) const = 0;
  public:
    virtual ~Mode() {};
    void set_wd(const WordData & wd) {
        throw "Non-compatible mode and worddata";
    }
    virtual void set_wd(const WordTable & wt) {
        throw "Non-compatible mode and worddata";
    }
    virtual void set_wd(const WordTree & wt) {
        throw "Non-compatible mode and worddata";
    }
    bool good_strat(const Strategy & s) const {
        if (!has_wd())
            throw "WordData wasn't set!";
        return good_strat_ch(s); 
    }
};

#endif
