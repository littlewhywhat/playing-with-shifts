#ifndef MODE_H
#define MODE_H

#include <cstdint>

#include "strategy.h"
#include "wordtree.h"
#include "tnode.h"

class Mode {
  private:
    bool good_turn(Strategy & s, const TNode * node, uint32_t turn) const {
        if (turn == s.lim())
            return true;
        if (s.at(turn)) {
            if (node -> getChildren().size() != node -> MAX_CHILD)
                return false;
            for (TNode * child : node -> getChildren())
                if (!good_turn(s, child, turn + 1))
                    return false;
            return true;
        } else {
            for (TNode * child : node -> getChildren())
                if (good_turn(s, child, turn + 1))
                    return true;
            return false;
        }
    }
  public:
    bool good_strategy(Strategy & s, WordTree & wt) const {
        return good_turn(s, wt.root(), 0);
    }
};

#endif
