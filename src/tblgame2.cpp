#include <cstdint>
#include <map>
#include <utility>

#include "tblgame.h"
#include "tblgame2.h"

bool TblGame2::InverseLess::operator() (const uint64_t & a, const uint64_t & b) const {
    return (a & m_Mask) < (b & m_Mask);
}

bool TblGame2::play_tm(const uint64_t & max_comb_val, const uint64_t & s_val) const {
    InverseLess c(s_val);
    std::map<uint64_t, uint64_t, InverseLess> words_map(c);
    for (const auto & word : tbllang()) {
        auto search = words_map.find(word);
        if (search == words_map.end()) 
            words_map.insert(std::make_pair(word, 1)); 
        else {
            search -> second += 1;
            if (search -> second  == max_comb_val)
                return true;
        }
    }
    return false;
}
