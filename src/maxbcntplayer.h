#ifndef MAXBCNTPLAYER_H
#define MAXBCNTPLAYER_H

#include "console.h"
#include "strategy.h"
#include "player.h"

class MaxBCntPlayer : public Player {
  private:
    void precompute(Console & console) override;
    void compute(Console & console, const Strategy & strat) override;
    void postcompute(Console & console) override;
  public:
    MaxBCntPlayer() : Player() {}
    static Player * create() {
        return new MaxBCntPlayer();
    }
};

#endif
