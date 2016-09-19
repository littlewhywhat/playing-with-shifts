#ifndef MODE1_H
#define MODE1_H

#include <cstdint>

#include "mode.h"

class Mode1 : public Mode {
  public:
    ~Mode1() override {}  
    bool good_strat(const Strategy & s, const WordTable & wt) const override{
        
        uint32_t max = (uint32_t)1 << s.bids().size();
        for (uint32_t i = 0; i < max; i++) {
            i_lttr_vector id_letters;
            make_id_letters(id_letters, i, s);
            if (!wt.has(id_letters))
                return false;
        }
        return true;
    }
};

#endif
