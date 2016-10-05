#ifndef MAXBCNT_H
#define MAXBCNT_H

#include <cstdint>
#include <ostream>

#include "game.h"
#include "strategy.h"

class MaxBCnt {
  private:
    const Game & m_Game;
  public:
    MaxBCnt(const Game & game) : m_Game(game) {} 
    uint32_t compute(std::ostream * out) const {
        uint32_t max_bcnt = 0;   
        if (out)
            *out << "good strategies are: " << std::endl;
        uint64_t strat_bound = (uint64_t)1 << m_Game.wordlen();
        for (uint64_t strat_val = 1; strat_val < strat_bound; strat_val++) {
            Strategy strat(strat_val, m_Game.wordlen());
            uint32_t bcnt = strat.bcnt();
            if (bcnt > max_bcnt && m_Game.play(strat)) {
                if (out)
                    *out << strat << std::endl;
                max_bcnt = bcnt;
            }
        }
        return max_bcnt;
    }
};

#endif
