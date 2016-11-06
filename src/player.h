#ifndef PLAYER_H
#define PLAYER_H

#include "console.h"

class Player {
  protected:
    bool m_OutResult;
    bool m_OutLang;
    uint32_t m_Score;
    virtual void precompute(Console & console) {}
    virtual void compute(Console & console, const Strategy & strat) {}
    virtual void postcompute(Console & console) {}
    void reset_score() { m_Score = 0; }
  protected:
    Player() : m_OutResult(false), m_OutLang(false), m_Score(0) {}
  public:
    virtual ~Player() {}
    void set_out_lang(bool val) { m_OutLang = val; }
    void set_out_result(bool val) { m_OutResult = val;}
    uint32_t score() const { return m_Score; }
    void play(Console & console);
};

#endif
