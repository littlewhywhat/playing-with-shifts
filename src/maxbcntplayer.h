#ifndef MAXBCNTPLAYER_H
#define MAXBCNTPLAYER_H

#include "strategy.h"
#include "successplayer.h"

class MaxBCntPlayer : public SuccessPlayer {
  public:
    MaxBCntPlayer(const uint32_t & len) : SuccessPlayer(len) {}
    const Strategy & next_strategy(const uint32_t & score) override;

    static Player * create(const uint32_t & len) {
        return new MaxBCntPlayer(len);
    }
};

#endif
