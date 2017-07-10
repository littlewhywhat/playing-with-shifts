//
// Created by vaivorom on 3/23/17.
//

#include "gameserver.h"
    
GameServer::~GameServer() {
    for (auto & room : m_Rooms)
        delete room;
}

void GameServer::launch() {
    for (auto & room : m_Rooms) {
        try {
            room->launch();
        } catch (char const* e) {
            std::cout << e << std::endl;
        }
    }
}

void GameServer::add_room(GameRoom * room) {
    m_Rooms.push_back(room);
}
