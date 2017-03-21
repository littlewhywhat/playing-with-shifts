#ifndef TBLGAME_H
#define TBLGAME_H

#include <cstdint>

#include "strategy.h"
#include "game.h"
#include "tbllanguage.h"

class TblGame : public Game {
  private:
    TblLanguage * m_TblLang;
    bool play_ch(const Strategy & s) const override {
        if (!s.val())
            return true;
        const uint64_t max_comb_val = ((uint64_t) 1) << s.bcnt();
        if (max_comb_val > tbllang().size())
            return false;
        return play_tm(max_comb_val, s.val());
    }     
    virtual bool play_tm(const uint64_t & max_comb_val, const uint64_t & s_val) const = 0;
  protected:
    const TblLanguage & tbllang() const { return *m_TblLang; }
  public:
    TblGame() : Game() {
        m_TblLang = new TblLanguage();
        set_lang(m_TblLang);
    }
    virtual ~TblGame() { }
};

#endif
