#ifndef TBLGAME_H
#define TBLGAME_H

#include <cstdint>

#include "strategy.h"
#include "game.h"
#include "wordtable.h"

class TblGame : public Game {
  private:
    WordTable * m_WT;
    bool has_wd() const override {
        return m_WT;
    }
    bool play_ch(const Strategy & s) const override {
        if (!s.val())
            return true;
        const uint64_t max_comb_val = ((uint64_t) 1) << s.bcnt();
        if (max_comb_val > wt().size())
            return false;
        return play_tm(max_comb_val, s.val());
    }     
    virtual bool play_tm(const uint64_t & max_comb_val, const uint64_t & s_val) const = 0;
  protected:
    const WordTable & wt() const {
        return *m_WT;
    }
  public:
    TblGame(const uint32_t & wordlen) {
        m_WT = new WordTable(wordlen);
    }
    virtual ~TblGame() {
        delete m_WT;
    };
    WordData & wd() const override {
        return *m_WT;
    }
    const uint32_t & wordlen() const override {
        return wt().wordlen();
    }
};

#endif
