//
// Created by littlewhywhat on 3/19/17.
//

#include "judge.h"

bool Judge::run(const Game &game, const Strategy &strategy) {
    bool is_success = game.play(strategy);
    if (is_success)
        update_score(strategy);
    return is_success;
}

void Judge::update_score(const Strategy &strategy) {
    uint32_t score = strategy.bcnt();
    if (score > m_MaxScore)
        m_MaxScore = score;
}

void Judge::announce_to(Printer &printer) { printer.send_to_announce(*this); }

void Judge::print_score_to(Printer &printer) { printer.send_to_print_score(*this); }
