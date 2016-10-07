#ifndef MAXBCNTPLAYER_H
#define MAXBCNTPLAYER_H

#include <cstdint>

#include "console.h"
#include "strategy.h"
#include "player.h"

class MaxBCntPlayer : public Player {
  private:
    uint32_t m_MaxBCnt; 
    void precompute(Console & console) override {
        m_MaxBCnt = 0;
        if (m_OutResult)
            console.out() << "good strategies are:" << std::endl;
    }
    void compute(Console & console, const Strategy & strat) override {
        uint32_t bcnt = strat.bcnt();
        if (bcnt > m_MaxBCnt && console.play(strat)) {
            if (m_OutResult)
                console.out() << strat << std::endl;
            m_MaxBCnt = bcnt;
        }
    }
    void postcompute(Console & console) override {
        if (m_OutResult)
            console.out() << "max = " << m_MaxBCnt << std::endl;
    }
  public:
    MaxBCntPlayer() : Player() {}
    const uint32_t & max_bcnt() const {
        return m_MaxBCnt;
    }
};

#endif
