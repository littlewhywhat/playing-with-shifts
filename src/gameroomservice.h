//
// Created by vaivorom on 3/23/17.
//

#ifndef PLAYING_WITH_SHIFTS_GAMEROOMSERVICE_H
#define PLAYING_WITH_SHIFTS_GAMEROOMSERVICE_H


#include "gameroom.h"
#include "gamesessionservice.h"

class GameRoomService {
  public:
    GameRoom * create(const std::vector<uint32_t> & modes, std::string & player_tag, const uint32_t & wordlen);

  private:
    const GameSessionService & get_gamesession_service() const;
};


#endif //PLAYING_WITH_SHIFTS_GAMEROOMSERVICE_H
