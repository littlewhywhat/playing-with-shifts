#ifndef MODE_H
#define MODE_H

#include "strategy.h"
#include "wordtable.h"
#include "i_lttr_vector.h"

class Mode {
  protected:
  	void make_id_letters(i_lttr_vector & id_letters, uint32_t data, const Strategy & s) const {
            uint32_t mask = 1;
            for (uint32_t bid : s.bids()) {
                char letter = (data & mask) + '0';
                id_letters.push_back(std::make_pair(bid, letter));
                data >>= 1;
            }
        }
  public:
    virtual ~Mode() {};
    virtual bool good_strat(const Strategy & s, const WordTable & wt) const = 0;     
};

#endif
