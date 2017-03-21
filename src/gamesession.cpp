//
// Created by littlewhywhat on 3/20/17.
//

#include "gamesession.h"

void GameSession::reset() {
    get_game().reset();
    get_judge().reset();
    get_player().reset();
}

Judge &GameSession::get_judge() {
    return *m_Judge;
}

const Judge &GameSession::get_judge() const {
    return *m_Judge;
}

void GameSession::run(const Language &lang) {
    reset();
    get_game().load(lang);
    while (m_Player -> has_next()) {
        const Strategy & strategy = get_player().next_strategy(get_judge().current_score());
        if (get_judge().run(get_game(), strategy))
            save_strategy(strategy);
    }
}

GameSession::~GameSession() {
    delete m_Game;
    delete m_Player;
    delete m_Judge;
}
