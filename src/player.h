#ifndef PLAYER_H
#define PLAYER_H

#include <cstdint>
#include "strategy.h"

class Player {
  private:
    uint32_t m_Score;
  protected:
    Player() : m_Score(0) {}
  public:
    virtual bool has_next() const = 0;
    virtual const Strategy & next_strategy(const uint32_t & score) = 0;
    virtual void reset() { m_Score = 0; };
    virtual ~Player() {}
};

#endif
