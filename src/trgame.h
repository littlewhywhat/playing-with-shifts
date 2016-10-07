#ifndef TRGAME_H
#define TRGAME_H

#include "wordtree.h"
#include "game.h"
#include "tnode.h"

class TrGame : public Game {
  private:
    WordTree * m_WT;
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
    const WordTree & wt() const {
        return *m_WT;
    }
  protected:
    bool has_wd() const override {
        return m_WT;
    }
    bool play_ch(const Strategy & s) const override {
        return play_rem(wt().root(), s.val(), s.length());    
    }
  public:
    TrGame(const uint32_t & wordlen) : m_WT(new WordTree(wordlen)) {}
    ~TrGame() {
        delete m_WT;
    }
    const uint32_t & wordlen() const override {
        return wt().wordlen();
    }
    WordData & wd() const override {
        return *m_WT;
    }
    static Game * create(const uint32_t & wordlen) {
        return new TrGame(wordlen);
    }
};

#endif
