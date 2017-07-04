//
// Created by vaivorom on 3/23/17.
//

#ifndef PLAYING_WITH_SHIFTS_GAMESESSIONSERVICE_H
#define PLAYING_WITH_SHIFTS_GAMESESSIONSERVICE_H


#include <cstdint>
#include <string>
#include "gamesession.h"
#include "playerfactory.h"
#include "gamefactory.h"

class GameSessionService {
  public:
    GameSession * create(const uint32_t & mode, const std::string & player_id, const uint32_t & wordlen) const {
        return new GameSession(create_game(mode), create_player(player_id, wordlen), new Judge());
    }

  private:
    Player * create_player(const std::string & tag, const uint32_t & wordlen) const {
        Player * p = PlayerFactory::get()->create_instance(tag, wordlen);
        if (p)
            return p;
        throw "Wrong player!";
    }
    Game * create_game(const uint32_t & mode) const {
        Game * game = GameFactory::get() -> create_instance(mode);
        if (game)
            return game;
        throw "Wrong game specifier";
    }

};


#endif //PLAYING_WITH_SHIFTS_GAMESESSIONSERVICE_H
