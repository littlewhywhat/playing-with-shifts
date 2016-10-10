#ifndef MAXBCNTPLAYER_H
#define MAXBCNTPLAYER_H

#include <cstdint>

#include "console.h"
#include "strategy.h"
#include "player.h"

class MaxBCntPlayer : public Player {
  private:
    void precompute(Console & console) override {
        if (m_OutResult)
            console.out() << "good strategies are:" << std::endl;
    }
    void compute(Console & console, const Strategy & strat) override {
        uint32_t bcnt = strat.bcnt();
        if (bcnt > m_Score && console.play(strat)) {
            if (m_OutResult)
                console.out() << strat << std::endl;
            m_Score = bcnt;
        }
    }
    void postcompute(Console & console) override {
        if (m_OutResult)
            console.out() << "max = " << m_Score << std::endl;
    }
  public:
    MaxBCntPlayer() : Player() {}
    static Player * create() {
        return new MaxBCntPlayer();
    }
};

#endif
