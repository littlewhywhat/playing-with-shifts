#ifndef TBLGAME2_H
#define TBLGAME2_H

#include <cstdint>

#include "tblgame.h"

class TblGame2 : public TblGame {
  private:
    class InverseLess {
      private:
        uint64_t m_Mask;
      public:
        InverseLess(const uint64_t & mask) : m_Mask(~mask) {}
        bool operator() (const uint64_t & a, const uint64_t & b) const;
    };
    bool play_tm(const uint64_t & max_comb_val, const uint64_t & s_val) const override;
  public:
    TblGame2(const uint32_t & wordlen) : TblGame(wordlen) {}
    ~TblGame2() override {}
    static Game * create(const uint32_t & wordlen) {
        return new TblGame2(wordlen);
    }
};

#endif
