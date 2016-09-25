#ifndef MODE3_H
#define MODE3_H

#include "wordtree.h"
#include "mode.h"
#include "tnode.h"

class Mode3 : public Mode {
  private:
    bool recurse_gs(const TNode & node, uint64_t rem_strat) const {
        if (node.is_leaf())
            return true;
        if (rem_strat & 1)
            return node.has_zero() && node.has_one() &&
                   recurse_gs(node.zero(), rem_strat >> 1) && 
                   recurse_gs(node.one(), rem_strat >> 1);
        else
            return (node.has_zero() && recurse_gs(node.zero(), rem_strat >> 1)) || 
                   (node.has_one() && recurse_gs(node.one(), rem_strat >> 1));
    }
  public:
    bool good_strat(const Strategy & s, const WordTree & wt) const override {
        return recurse_gs(wt.root(), s.val());    
    }
};

#endif
