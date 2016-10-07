#ifndef TRGAME_H
#define TRGAME_H

#include "trlanguage.h"
#include "game.h"
#include "tnode.h"

class TrGame : public Game {
  private:
    TrLanguage * m_Lang;
    bool play_rem(const TNode & node, uint64_t rem_strat, uint32_t wordlen) const {
        if (node.is_leaf()) {
            if (wordlen == 0)
                return true;
            else
                return false;
        }
        if (rem_strat & 1)
            return node.has_zero() && node.has_one() &&
                   play_rem(node.zero(), rem_strat >> 1, wordlen - 1) && 
                   play_rem(node.one(), rem_strat >> 1, wordlen - 1);
        else
            return (node.has_zero() && play_rem(node.zero(), rem_strat >> 1, wordlen - 1)) || 
                   (node.has_one() && play_rem(node.one(), rem_strat >> 1, wordlen - 1));
    }
    const TrLanguage & trlang() const {
        return *m_Lang;
    }
  protected:
    bool has_lang() const override {
        return m_Lang;
    }
    bool play_ch(const Strategy & s) const override {
        return play_rem(trlang().root(), s.val(), s.length());    
    }
  public:
    TrGame(const uint32_t & wordlen) : m_Lang(new TrLanguage(wordlen)) {}
    ~TrGame() {
        delete m_Lang;
    }
    const uint32_t & wordlen() const override {
        return lang().wordlen();
    }
    Language & lang() const override {
        return *m_Lang;
    }
    static Game * create(const uint32_t & wordlen) {
        return new TrGame(wordlen);
    }
};

#endif
