#ifndef PLAYER_H
#define PLAYER_H

#include <cstdint>
#include "strategy.h"

/*
 *  Iterator over strategies to play.
 *  Computes next strategy by provided score from previous strategy.
 *  Has some strategy to start with and to end with.
 */ 

class Player {
  protected:
    Player() {}
  public:
    virtual bool has_next() const = 0;
    virtual const Strategy & next_strategy(const uint32_t & score) = 0;
    virtual void reset() = 0;
    virtual ~Player() {}
};

#endif
