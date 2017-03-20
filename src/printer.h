#ifndef SHIFTS_PRINTER_H
#define SHIFTS_PRINTER_H

#include <set>
#include "strategy.h"
#include "player.h"
#include "judge.h"
#include "gamesession.h"

class Judge;
class SessionResults;

class Printer {
  private:
    bool m_OutLang;
    bool m_OutScore;
    bool m_OutGame;
    bool m_OutTest;
  protected:
    void print(const std::set<std::string> & wordset);
    void print(const Strategy & strategy) const;
    void announce(const Judge & judge) const;
    void print_score(const Judge & judge) const;
    void print_score(const uint32_t &score) const;
  public:
    Printer() : m_OutLang(true), m_OutScore(true), m_OutGame(true), m_OutTest(false) {}
    void set_out_lang(bool val) { m_OutLang = val; }
    void set_out_score(bool val) { m_OutScore = val; }
    void set_out_game(bool val) { m_OutGame = val; }
    void set_out_test(bool val) { m_OutTest = val; }
    void send_to_print(const std::set<std::string> & wordset) {
        if (m_OutLang) print(wordset);
    }
    void send_to_print(const Strategy & strategy) const {
        if (m_OutGame) print(strategy);
    }
    void send_to_announce(const Judge & judge) const {
        if (m_OutGame) announce(judge);
    }
    void send_to_print_score(const Judge & judge) const {
        if (m_OutScore) print_score(judge);
    }
    void send_to_print_score(const uint32_t & score) const {
        if (m_OutScore) print_score(score);
    }
    void send_to_print(const SessionResults & results);
};


#endif //SHIFTS_PRINTER_H
