#ifndef SuccessPLAYER_H
#define SuccessPLAYER_H

#include "console.h"
#include "strategy.h"
#include "player.h"

virtual void SuccessPlayer::compute(Console & console, const Strategy & strat) {
    if (console.play(strat) && m_OutResult)
        console.out() << strat << std::endl;
}

#endif
