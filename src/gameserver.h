//
// Created by vaivorom on 3/23/17.
//

#ifndef PLAYING_WITH_SHIFTS_GAMESERVERSERVER_H
#define PLAYING_WITH_SHIFTS_GAMESERVERSERVER_H

#include <iostream> 

#include "language.h"
#include "gameroom.h"
#include "appcontext.h"

/*
 *  Manages and stores several gamerooms.
 *  Launches them sequentially.
 *  On error outputs exception and continues to next room.
 */
class GameServer {
  public:
    ~GameServer(); 
    void launch();
    void add_room(GameRoom * room);
  private:
    std::vector<GameRoom*> m_Rooms;
};


#endif //PLAYING_WITH_SHIFTS_GAMESERVERSERVER_H
