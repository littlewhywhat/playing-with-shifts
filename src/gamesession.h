//
// Created by littlewhywhat on 3/20/17.
//

#ifndef SHIFTS_GAMESESSION_H
#define SHIFTS_GAMESESSION_H


#include <list>
#include "game.h"
#include "judge.h"

//TODO make class private somehow
class SessionResults {
  private:
    uint32_t m_Score;
    std::list<Strategy> m_Strategies;
  public:
    SessionResults() : m_Score(0) {}
    void set_score(const uint32_t & score) {
        m_Score = score;
    }
    void add_strategy(const Strategy & strategy) {
        m_Strategies.push_back(strategy);
    }
    void clear() {
        m_Score = 0;
        m_Strategies.clear();
    }
    const uint32_t & get_score() const {
        return m_Score;
    }
    const std::list<Strategy> & get_strategies() const {
        return m_Strategies;
    }
};

class GameSession {
  private:
    Game & m_Game;
    Judge & m_Judge;
    Player & m_Player;
    SessionResults m_Results;
    void save_strategy(const Strategy &strategy) {
        m_Results.add_strategy(strategy);
    }
    void save_score(const uint32_t & score) {
        m_Results.set_score(score);
    }
  public:
    GameSession(Game & game, Judge & judge, Player & player) :
            m_Game(game), m_Judge(judge), m_Player(player) {}
    ~GameSession() {
        reset();
    }
    void run(const std::set<std::string> & lang) {
        reset();
        m_Game.load(lang);
        while (m_Player.has_next()) {
            const Strategy & strategy = m_Player.next_strategy(m_Judge.current_score());
            if (m_Judge.run(m_Game, strategy))
                save_strategy(strategy);
        }
        save_score(m_Judge.current_score());
    }
    const SessionResults & results() {
        return m_Results;
    };

    void reset() {
        m_Game.reset();
        m_Judge.reset();
        m_Player.reset();
    }

};


#endif //SHIFTS_GAMESESSION_H
