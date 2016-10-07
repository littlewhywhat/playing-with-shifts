#ifndef TBLGAME2_H
#define TBLGAME2_H

#include <cstdint>
#include <map>
#include <utility>

#include "tblgame.h"

class TblGame2 : public TblGame {
  private:
    class InverseLess {
      private:
        uint64_t m_Mask;
      public:
        InverseLess(const uint64_t & mask) : m_Mask(~mask) {}
        bool operator() (const uint64_t & a, const uint64_t & b) const {
            return (a & m_Mask) < (b & m_Mask);
        }
    };
    bool play_tm(const uint64_t & max_comb_val, const uint64_t & s_val) const override {
        InverseLess c(s_val);
        std::map<uint64_t, uint64_t, InverseLess> words_map(c);
        for (auto word : tbllang()) {
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
  public:
    TblGame2(const uint32_t & wordlen) : TblGame(wordlen) {}
    ~TblGame2() override {}
    static Game * create(const uint32_t & wordlen) {
        return new TblGame2(wordlen);
    }
};

#endif
