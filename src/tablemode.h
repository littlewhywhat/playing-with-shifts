#ifndef TABLEMODE_H
#define TABLEMODE_H

#include <cstdint>
#include <vector>

#include "strategy.h"
#include "wordtable.h"

class TableMode : public Mode{
  protected:
    virtual bool gs_mode(const std::vector<uint64_t> & words, const uint64_t & max_comb_val, const uint64_t & s_val) const = 0;
  public:
    virtual ~TableMode() {};
    bool good_strat(const Strategy & s, const WordTable & wt) const override {
        if (!s.val())
            return true;
        const std::vector<uint64_t> & words = wt.words();
        const uint64_t max_comb_val = ((uint64_t) 1) << s.Bcnt();
        if (max_comb_val > words.size())
            return false;
        return gs_mode(wt.words(), max_comb_val, s.val());
    }     
};

#endif
