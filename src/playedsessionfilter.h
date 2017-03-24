//
// Created by vaivorom on 3/24/17.
//

#ifndef SHIFTS_PLAYEDSESSIONFILTER_H
#define SHIFTS_PLAYEDSESSIONFILTER_H


#include <cstdint>
#include <cstdlib>


class GameSession;

class PlayedSessionFilter {
  private:
    uint32_t * m_Score;
  public:
    PlayedSessionFilter() : m_Score(NULL) {}
    ~PlayedSessionFilter() { delete m_Score; }
    bool accepts(const GameSession & session);
};


#endif //SHIFTS_PLAYEDSESSIONFILTER_H
