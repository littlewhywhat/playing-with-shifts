//
// Created by vaivorom on 3/23/17.
//

#ifndef PLAYING_WITH_SHIFTS_GAMESERVERSERVER_H
#define PLAYING_WITH_SHIFTS_GAMESERVERSERVER_H


#include "language.h"
#include "gameroom.h"
#include "appcontext.h"

class GameServer {
  public:
    GameServer() : m_Printer(AppContext::get().get_printer()) {}
    ~GameServer() {
        for (auto & room : m_Rooms)
            delete room;
    }
    void launch() {
        for (auto & room : m_Rooms)
            room->launch();
    }
    void add_room(GameRoom * room) {
        m_Rooms.push_back(room);
    }
  private:
    const Printer & m_Printer;
    std::vector<GameRoom*> m_Rooms;
};


#endif //PLAYING_WITH_SHIFTS_GAMESERVERSERVER_H
