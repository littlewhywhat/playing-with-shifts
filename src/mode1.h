#ifndef MODE1_H
#define MODE1_H

#include <cstdint>

#include "strategy.h"
#include "wordtree.h"
#include "tnode.h"
#include "mode.h"
#include "alphabet.h"

class Mode1 : public Mode {
  private:
    bool good_turn(Strategy & s, const TNode * node, uint32_t turn, Alphabet & alpha) {
        if (turn == s.lim())
            return true;
        if (s.at(turn)) {
            for (char letter : alpha.letters()) {
                bool has = false;
                for (TNode * child : node -> getChildren(letter))
                    if (good_turn(s, child, turn + 1, alpha)) {
                        has = true;
                        break;
                    }
                if (!has)
                    return false;
            }
            return true;
        } else {
            for (TNode * child : node -> getChildren())
                if (good_turn(s, child, turn + 1, alpha))
                    return true;
            return false;
        }
    }
  public:
    ~Mode1() override {}
    bool good_strategy(Strategy & s, WordTree & wt, Alphabet & alpha) override{
        return good_turn(s, wt.root(), 0, alpha);
    }
};

#endif
