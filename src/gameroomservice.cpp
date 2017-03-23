//
// Created by vaivorom on 3/23/17.
//

#include "gameroomservice.h"
#include "appcontext.h"

GameRoom *GameRoomService::create(const std::vector<uint32_t> &modes, std::string &player_tag, const uint32_t &wordlen) {
    GameRoom * room = new GameRoom();
    for (auto & mode : modes)
        room -> add_session(get_gamesession_service().create(mode, player_tag, wordlen));
    room -> set_wordlen(wordlen);
    return room;
}

const GameSessionService &GameRoomService::get_gamesession_service() const {
    return AppContext::get().get_gamesession_service();
}
