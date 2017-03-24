//
// Created by vaivorom on 3/24/17.
//

#include "playedsessionfilter.h"
#include "gamesession.h"
bool PlayedSessionFilter::accepts(const GameSession &session) {
    const uint32_t & score = session.get_judge().current_score();
    if (!m_Score) {
        m_Score = new uint32_t(score);
        return true;
    }
    return *m_Score != score;
}
