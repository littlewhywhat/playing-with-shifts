#include "wordtree.h"
#include "game.h"
#include "trgame.h"

bool TrGame::play_rem(const TNode & node, uint64_t rem_strat, uint32_t wordlen) const {
    if (node.is_leaf())
        return wordlen == 0;
    if (rem_strat & 1)
        return node.has_zero() && node.has_one() &&
               play_rem(node.zero(), rem_strat >> 1, wordlen - 1) && 
               play_rem(node.one(), rem_strat >> 1, wordlen - 1);
    else
        return (node.has_zero() && play_rem(node.zero(), rem_strat >> 1, wordlen - 1)) || 
               (node.has_one() && play_rem(node.one(), rem_strat >> 1, wordlen - 1));
}
bool TrGame::play(const Strategy & s) const {
    return play_rem(trlang().root(), s.val(), s.length());    
}
