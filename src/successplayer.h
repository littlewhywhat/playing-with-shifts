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
    SimplePlayer() : m_OutResult(false), m_OutLang(false), m_Score(0) {}
};

#endif
