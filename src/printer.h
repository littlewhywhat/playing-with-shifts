#ifndef SHIFTS_PRINTER_H
#define SHIFTS_PRINTER_H

#include "strategy.h"
#include "player.h"
#include "judge.h"
#include "gamesession.h"
#include "playedsessionfilter.h"

class Judge;
class GameSession;

class Printer {
  private:
    bool m_OutLang;
    bool m_OutScore;
    bool m_OutGame;
    bool m_OutTest;
    const PlayedSessionFilter * m_Filter;
  protected:
    void print(const Language & wordset) const;
    void print(const Strategy & strategy) const;
    void announce(const Judge & judge) const;
    void print_score(const uint32_t &score) const;
  public:
    Printer() : m_OutLang(true), m_OutScore(true), m_OutGame(true), m_OutTest(false), m_Filter(NULL) {}
    ~Printer() {
        delete m_Filter;
    }
    void set_out_lang(bool val) { m_OutLang = val; }
    void set_out_score(bool val) { m_OutScore = val; }
    void set_out_game(bool val) { m_OutGame = val; }
    void set_out_test(bool val) { m_OutTest = val; }
    void set_filter(const PlayedSessionFilter * filter) { m_Filter = filter; }
    void send_to_print(const Language & wordset) const {
        if (m_OutLang) print(wordset);
    }
    void send_to_print(const Strategy & strategy) const {
        if (m_OutGame) print(strategy);
    }
    void send_to_announce(const Judge & judge) const {
        if (m_OutGame) announce(judge);
    }

    void send_to_print_score(const uint32_t & score) const {
        if (m_OutScore) print_score(score);
    }
    void print(const GameRoom & room) const;

    void send_to_print(const GameSession &session) const;
};


#endif //SHIFTS_PRINTER_H
