#include <cstdint>

#include "console.h"
#include "strategy.h"
#include "maxbcntplayer.h"

void MaxBCntPlayer::precompute(Console & console) override {
    if (m_OutResult)
        console.out() << "good strategies are:" << std::endl;
}
void MaxBCntPlayer::compute(Console & console, const Strategy & strat) override {
    uint32_t bcnt = strat.bcnt();
    if (bcnt > m_Score && console.play(strat)) {
        if (m_OutResult)
            console.out() << strat << std::endl;
        m_Score = bcnt;
    }
}
void MaxBCntPlayer::postcompute(Console & console) override {
    if (m_OutResult)
        console.out() << "max = " << m_Score << std::endl;
}
