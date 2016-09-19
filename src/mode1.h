#ifndef MODE1_H
#define MODE1_H

#include <cstdint>

#include "mode.h"

class Mode1 : public Mode {
  public:
    ~Mode1() override {}  
    bool good_strat(const Strategy & s, const WordTable & wt) const override{
        
        uint32_t max_comb_val = (uint32_t)1 << s.bids().size();
        for (uint32_t comb_val = 0; comb_val < max_comb_val; comb_val++) {
            Comb comb(comb_val, s);
            if (!wt.has(comb))
                return false;
        }
        return true;
    }
};

#endif
