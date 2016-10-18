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
        bool operator() (const uint64_t & a, const uint64_t & b) const;
    };
    bool play_tm(const uint64_t & max_comb_val, const uint64_t & s_val) const override;
  public:
    TblGame1(const uint32_t & wordlen) : TblGame(wordlen) {}
    ~TblGame1() override {}  
    static Game * create(const uint32_t & wordlen) { return new TblGame1(wordlen); }
};

#endif
