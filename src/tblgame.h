#ifndef TBLGAME_H
#define TBLGAME_H

#include <cstdint>

#include "strategy.h"
#include "game.h"
#include "tbllanguage.h"

class TblGame : public Game {
  private:
    TblLanguage * m_Lang;
    bool has_lang() const override {
        return m_Lang;
    }
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
    const TblLanguage & tbllang() const {
        return *m_Lang;
    }
  public:
    TblGame(const uint32_t & wordlen) {
        m_Lang = new TblLanguage(wordlen);
    }
    virtual ~TblGame() {
        delete m_Lang;
    };
    Language & lang() const override {
        return *m_Lang;
    }
    const uint32_t & wordlen() const override {
        return lang().wordlen();
    }
};

#endif
