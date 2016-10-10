#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H

#include <cstdint>
#include <string>

#include "player.h"
#include "maxbcntplayer.h"
#include "langoutplayer.h"

class PlayerFactory {
  private:
    PlayerFactory() {
    	reg_player("player", &Player::create);
    	reg_player("maxbcnt", &MaxBCntPlayer::create);
    	reg_player("langout", &LangOutPlayer::create);
    }
    PlayerFactory(const PlayerFactory & src) = delete;
    PlayerFactory & operator = (const PlayerFactory & src) = delete;
    typedef Player* (*create_player_fn)();
    std::map<std::string, create_player_fn> player_map;
  public:
    ~PlayerFactory() {};

    static PlayerFactory * get() {
        static PlayerFactory singleton;
        return &singleton;
    }

    void reg_player(const std::string & type, create_player_fn func) {
    	player_map[type] = func;
    }
    Player * create_instance(const std::string & type) const {
    	auto search = player_map.find(type);
    	if (search != player_map.end())
    		return search -> second();
    	return NULL;
    }
};

#endif
