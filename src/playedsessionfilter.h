//
// Created by vaivorom on 3/24/17.
//

#ifndef SHIFTS_PLAYEDSESSIONFILTER_H
#define SHIFTS_PLAYEDSESSIONFILTER_H


#include <cstdint>
#include <cstdlib>

class GameRoom;

class PlayedSessionFilter {
  public:
    bool accepts(const GameRoom & session) const;
};


#endif //SHIFTS_PLAYEDSESSIONFILTER_H
