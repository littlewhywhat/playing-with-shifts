#include <cstdint>
#include <set>

#include "tblgame1.h"

bool TblGame1::Less::operator() (const uint64_t & a, const uint64_t & b) const {
    return (a & m_Mask) < (b & m_Mask);
}
bool TblGame1::play_tm(const uint64_t & max_comb_val, const uint64_t & s_val) const {
    Less less(s_val);
    std::set<uint64_t, Less> combset(less);
    for (const auto & word : tbllang()) 
        if (combset.find(word) == combset.end()) {
            combset.insert(word);
            if (combset.size() == max_comb_val)
                return true;
        }
    return false;
}
