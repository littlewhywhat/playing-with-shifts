//
// Created by littlewhywhat on 3/20/17.
//

#ifndef SHIFTS_GAMESESSION_H
#define SHIFTS_GAMESESSION_H

#include <list>
#include "game.h"
#include "judge.h"

class Judge;

class GameSession {
  private:
    Game * m_Game;
    Judge * m_Judge;
    Player * m_Player;
    std::list<Strategy> m_Results;
    void save_strategy(const Strategy &strategy) {
        m_Results.push_back(strategy);
    }
    Game & get_game() { return *m_Game; }
    Player & get_player() { return *m_Player; }
  public:
    GameSession(Game * game, Player * player, Judge * judge) :
            m_Game(game), m_Judge(judge), m_Player(player) {}
    ~GameSession();
    void run(const Language & lang);
    const std::list<Strategy> & won_history() const {
        return m_Results;
    };
    Judge & get_judge();
    const Judge & get_judge() const;

    void reset();

};


#endif //SHIFTS_GAMESESSION_H
