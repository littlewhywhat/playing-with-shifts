#include "console.h"
#include "strategy.h"
#include "successplayer.h"

bool SuccessPlayer::has_next() const {
    return m_PrevStrategy.val() != m_MaxStrategy.val();
}

const Strategy &SuccessPlayer::next_strategy(const uint32_t &score) {
    m_PrevStrategy.increment();
    return m_PrevStrategy;
}

void SuccessPlayer::reset() {
    Player::reset();
    m_PrevStrategy = Strategy::MIN(m_PrevStrategy.length());
}
