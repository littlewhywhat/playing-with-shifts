#ifndef TRGAME_H
#define TRGAME_H

#include "wordtree.h"
#include "game.h"
#include "tnode.h"

class TrGame : public Game {
  private:
    WordTree * m_TrLang;
    bool play_rem(const TNode & node, uint64_t rem_strat, uint32_t wordlen) const;
    const WordTree & trlang() const { return *m_TrLang; }
  protected:
    bool play_ch(const Strategy & s) const override;
  public:
    TrGame() : Game() {
        m_TrLang = new WordTree();
        set_lang(m_TrLang);
    }
    static Game * create() { return new TrGame(); }
};

#endif
