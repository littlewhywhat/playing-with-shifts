#include "console.h"
#include "strategy.h"
#include "successplayer.h"

void SuccessPlayer::compute(Console & console, const Strategy & strat) {
    if (console.play(strat) && m_OutResult)
        console.out() << strat << std::endl;
}
