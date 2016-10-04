#ifndef MODE3_H
#define MODE3_H

#include "wordtree.h"
#include "mode.h"
#include "tnode.h"

class Mode3 : public Mode {
  private:
    const WordTree * m_WT;
    bool good_strat_rem(const TNode & node, uint64_t rem_strat, uint32_t wordlen) const {
        if (node.is_leaf()) {
            if (wordlen == 0)
                return true;
            else
                return false;
        }
        if (rem_strat & 1)
            return node.has_zero() && node.has_one() &&
                   good_strat_rem(node.zero(), rem_strat >> 1, wordlen - 1) && 
                   good_strat_rem(node.one(), rem_strat >> 1, wordlen - 1);
        else
            return (node.has_zero() && good_strat_rem(node.zero(), rem_strat >> 1, wordlen - 1)) || 
                   (node.has_one() && good_strat_rem(node.one(), rem_strat >> 1, wordlen - 1));
    }
    const WordTree & get_wt() const {
        return *m_WT;
    }
  protected:
    bool has_wd() const override {
        return m_WT;
    }
    bool good_strat_ch(const Strategy & s) const override {
        return good_strat_rem(get_wt().root(), s.val(), s.length());    
    }
  public:
    void set_wd(const WordTree & wt) override {
        m_WT = &wt;
    }
};

#endif
