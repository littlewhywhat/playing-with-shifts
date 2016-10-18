#ifndef TRGAME_H
#define TRGAME_H

#include "trlanguage.h"
#include "game.h"
#include "tnode.h"

class TrGame : public Game {
  private:
    TrLanguage * m_Lang;
    bool play_rem(const TNode & node, uint64_t rem_strat, uint32_t wordlen) const;
    const TrLanguage & trlang() const { return *m_Lang; }
  protected:
    bool has_lang() const override { return m_Lang; }
    bool play_ch(const Strategy & s) const override;
  public:
    TrGame(const uint32_t & wordlen) : m_Lang(new TrLanguage(wordlen)) {}
    ~TrGame() {
        delete m_Lang;
    }
    const uint32_t & wordlen() const override { return lang().wordlen(); }
    Language & lang() const override { return *m_Lang; }
    static Game * create(const uint32_t & wordlen) { return new TrGame(wordlen); }
};

#endif
