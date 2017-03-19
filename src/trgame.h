#ifndef TRGAME_H
#define TRGAME_H

#include "trlanguage.h"
#include "game.h"
#include "tnode.h"

class TrGame : public Game {
  private:
    TrLanguage * m_TrLang;
    bool play_rem(const TNode & node, uint64_t rem_strat, uint32_t wordlen) const;
    const TrLanguage & trlang() const { return *m_TrLang; }
  protected:
    bool play_ch(const Strategy & s) const override;
  public:
    TrGame(const uint32_t & wordlen) : Game() {
        m_TrLang = new TrLanguage(wordlen);
        set_lang(m_TrLang);
    }
    // TODO decide if destructor should be virtual here
    virtual ~TrGame() {}
    static Game * create(const uint32_t & wordlen) { return new TrGame(wordlen); }
};

#endif
