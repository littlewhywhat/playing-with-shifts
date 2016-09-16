#ifndef MODE1_H
#define MODE1_H

#include <cstdint>

#include "mode.h"

class Mode1 : public Mode {
  public:
    ~Mode1() override {}  
    bool good_strat(const Strategy & s, const WordTable & wt) const override{
        uint32_t mask = 1;
        uint32_t max = (uint32_t)1 << s.bids().size();
        for (uint32_t i = 0; i < max; i++) {
            std::vector<std::pair<uint32_t, char>> id_letters;
            uint32_t data = i;
            for (uint32_t bid : s.bids()) {
                char letter = (data & mask) + '0';
                id_letters.push_back(std::make_pair(bid, letter));
                data >>= 1;
            }
            if (!wt.has(id_letters))
                return false;
        }
        return true;
    }
};

#endif
