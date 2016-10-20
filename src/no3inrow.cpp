#include <cstdint>

#include "no3inrow.h"

bool No3inRow::is_relevant(uint64_t word, const uint32_t & wordlen) const {
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
