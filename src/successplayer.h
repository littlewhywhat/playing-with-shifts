#ifndef SuccessPLAYER_H
#define SuccessPLAYER_H

#include "console.h"
#include "player.h"

class SuccessPlayer : public Player {
  protected:
    virtual void precompute(Console & console) {}
    virtual void compute(Console & console, const Strategy & strat);
    virtual void postcompute(Console & console) {} 
  public:
    SuccessPlayer() : Player() {}
    static Player * create() { return new SuccessPlayer(); }
};

#endif
