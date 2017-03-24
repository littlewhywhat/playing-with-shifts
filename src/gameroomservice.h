//
// Created by vaivorom on 3/23/17.
//

#ifndef PLAYING_WITH_SHIFTS_GAMEROOMSERVICE_H
#define PLAYING_WITH_SHIFTS_GAMEROOMSERVICE_H


#include <vector>
#include "gamesessionservice.h"

class GameRoom;

class GameRoomService {
  public:
    GameRoom *create(const std::string & hostid, const std::string &langid, const std::vector<uint32_t> &modes, const std::string &player_tag,
                     const uint32_t &wordlen) const;

  private:
    const GameSessionService & get_gamesession_service() const;
};


#endif //PLAYING_WITH_SHIFTS_GAMEROOMSERVICE_H
