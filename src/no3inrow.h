#ifndef NO3INROW_H
#define NO3INROW_H

#include "langbuilder.h"

class No3inRow : public LangBuilder {
  public:
    bool is_relevant(uint64_t word, const uint32_t & wordlen) const override {
        uint32_t cnt_ones = 0;
        for (uint32_t i = 0; i < wordlen; i++) {
           uint32_t last_digit = word & 1;
           if (last_digit == 0)
               cnt_ones = 0;
           else if (cnt_ones == 2)
               return false;
           else
               cnt_ones++;
           word >>= 1;
        }
        return true;
    }
    static LangBuilder * create() {
       return new No3inRow(); 
    }
};

#endif
