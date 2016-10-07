#ifndef GAMEFACTORY_H
#define GAMEFACTORY_H

#include <cstdint>

#include "game.h"
#include "tblgame1.h"
#include "tblgame2.h"
#include "trgame.h"

class GameFactory {
  private:
    GameFactory() {
    	reg_game(1, &TblGame1::create);
    	reg_game(2, &TblGame2::create);
    	reg_game(3, &TrGame::create);
    }
    GameFactory(const GameFactory & src) = delete;
    GameFactory & operator = (const GameFactory & src) = delete;
    typedef Game* (*create_game_fn)(const uint32_t & wordlen);
    std::map<uint32_t, create_game_fn> game_map;
  public:
    ~GameFactory() {};

    static GameFactory * get() {
        static GameFactory singleton;
        return &singleton;
    }

    void reg_game(const uint32_t & type, create_game_fn func) {
    	game_map[type] = func;
    }
    Game * create_instance(const uint32_t & type, const uint32_t & wordlen) const {
    	auto search = game_map.find(type);
    	if (search != game_map.end())
    		return search -> second(wordlen);
    	return NULL;
    }
};

#endif
