//
// Created by vaivorom on 3/23/17.
//

#include "gameroomservice.h"
#include "gameroom.h"
#include "appcontext.h"

GameRoom *GameRoomService::create(const std::string & hostid,
                                  const std::string &langid, const std::vector<uint32_t> &modes,
                                  const std::string &player_tag,
                                  const uint32_t &wordlen) const {
    GameRoom * room = new GameRoom();
    for (auto & mode : modes)
        room -> add_session(get_gamesession_service().create(mode, player_tag, wordlen));
    room -> set_wordlen(wordlen);
    room -> set_langid(langid);
    room -> set_hostid(hostid);
    if (AppContext::get().sessionfilter_defined())
        room -> set_filter(AppContext::get().create_sessionfilter());
    return room;
}

const GameSessionService &GameRoomService::get_gamesession_service() const {
    return AppContext::get().get_gamesession_service();
}
