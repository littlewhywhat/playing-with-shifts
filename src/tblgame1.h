#ifndef TBLGAME1_H
#define TBLGAME1_H

#include <cstdint>
#include <set>

#include "tblgame.h"

class TblGame1 : public TblGame {
  private:
    class Less {
      private:
        uint64_t m_Mask;
      public:
        Less(const uint64_t & mask) : m_Mask(mask) {}
        bool operator() (const uint64_t & a, const uint64_t & b) const {
            return (a & m_Mask) < (b & m_Mask);
        }
    };
    bool play_tm(const uint64_t & max_comb_val, const uint64_t & s_val) const override{
        Less less(s_val);
        std::set<uint64_t, Less> combset(less);
        for (auto word : wt()) 
            if (combset.find(word) == combset.end()) {
                combset.insert(word);
                if (combset.size() == max_comb_val)
                    return true;
            }
        return false;
    }
  public:
    TblGame1(const uint32_t & wordlen) : TblGame(wordlen) {}
    ~TblGame1() override {}  
    static Game * create(const uint32_t & wordlen) {
        return new TblGame1(wordlen);
    }
};

#endif
