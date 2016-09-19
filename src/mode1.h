#ifndef MODE1_H
#define MODE1_H

#include <cstdint>

#include "mode.h"

class Mode1 : public Mode {
  public:
    ~Mode1() override {}  
    bool good_strat(const Strategy & s, const WordTable & wt) const override{
        
        uint64_t max_comb_val = (uint64_t)1 << s.bids().size();
        for (uint64_t comb_val = 0; comb_val < max_comb_val; comb_val++) {
            Comb comb(comb_val, s);
            if (!wt.has(comb))
                return false;
        }
        return true;
    }
};

#endif
