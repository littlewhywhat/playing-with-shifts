//
// Created by vaivorom on 3/24/17.
//

#include "playedsessionfilter.h"
#include "gameroom.h"

bool PlayedSessionFilter::accepts(const GameRoom &room) const {
    uint32_t score = room.get_sessions().front()->get_judge().current_score();
    for (auto & session : room.get_sessions())
        if (session->get_judge().current_score() != score)
            return true;
    return false;
}
