#include <cstdint>

#include "maxbcntplayer.h"

const Strategy &MaxBCntPlayer::next_strategy(const uint32_t &score) {
    SuccessPlayer::next_strategy(score);
    while (m_PrevStrategy.bcnt() <= score
                && has_next()) {
        m_PrevStrategy.increment();
    }
    return m_PrevStrategy;
}
