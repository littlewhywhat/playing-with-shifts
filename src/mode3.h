#ifndef MODE3_H
#define MODE3_H

#include "wordtree.h"
#include "mode.h"
#include "tnode.h"

class Mode3 : public Mode {
  private:
    const WordTree * m_WT;
    bool recurse_gs(const TNode & node, uint64_t rem_strat, uint32_t wordlen) const {
        if (node.is_leaf()) {
            if (wordlen == 0)
                return true;
            else
                return false;
        }
        if (rem_strat & 1)
            return node.has_zero() && node.has_one() &&
                   recurse_gs(node.zero(), rem_strat >> 1, wordlen - 1) && 
                   recurse_gs(node.one(), rem_strat >> 1, wordlen - 1);
        else
            return (node.has_zero() && recurse_gs(node.zero(), rem_strat >> 1, wordlen - 1)) || 
                   (node.has_one() && recurse_gs(node.one(), rem_strat >> 1, wordlen - 1));
    }
    const WordTree & wt() const {
        return *m_WT;
    }
  protected:
    bool has_wd() const override {
        return m_WT;
    }
    bool good_strat_ch(const Strategy & s) const override {
        return recurse_gs(wt().root(), s.val(), s.length());    
    }
  public:
    void set_wd(const WordTree & wt) override {
        m_WT = &wt;
    }
};

#endif
