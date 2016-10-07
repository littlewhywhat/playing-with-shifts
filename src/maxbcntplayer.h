#ifndef MAXBCNTPLAYER_H
#define MAXBCNTPLAYER_H

#include <cstdint>
#include <ostream>

#include "console.h"
#include "strategy.h"

class MaxBCntPlayer {
  private:
    bool m_OutResult;
    bool m_OutWD;
  public:
    MaxBCntPlayer() : m_OutResult(true), m_OutWD(true) {}
    uint32_t play(Console & console) const {
        if (m_OutWD)
            console.out() << "Building worddata..." << std::endl 
                          << console.wd() << std::endl;
        uint32_t max_bcnt = 0;   
        console.out() << "good strategies are: " << std::endl;
        uint64_t strat_bound = (uint64_t)1 << console.wordlen();
        for (uint64_t strat_val = 1; strat_val < strat_bound; strat_val++) {
            Strategy strat(strat_val, console.wordlen());
            uint32_t bcnt = strat.bcnt();
            if (bcnt > max_bcnt && console.play(strat)) {
                console.out() << strat << std::endl;
                max_bcnt = bcnt;
            }
        }
        if (m_OutResult)
            console.out() << "max = " << max_bcnt << std::endl;
        return max_bcnt;
    }
};

#endif
