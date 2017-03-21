//
// Created by littlewhywhat on 3/19/17.
//

#ifndef SHIFTS_JUDGE_H
#define SHIFTS_JUDGE_H


#include <cstdint>
#include "strategy.h"
#include "game.h"
#include "printer.h"

class Printer;

class Judge {
  private:
    uint32_t m_MaxScore;
    void update_score(const Strategy & strategy);
  public:
    Judge() : m_MaxScore(0) {}
    const uint32_t & current_score() const { return m_MaxScore; }
    void reset() { m_MaxScore = 0; }
    bool run(const Game & game, const Strategy & strategy);
    void announce_to(Printer & printer)const;
};


#endif //SHIFTS_JUDGE_H
