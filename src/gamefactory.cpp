#include <cstdint>

#include "gamefactory.h"
#include "game.h"
#include "tblgame1.h"
#include "tblgame2.h"
#include "trgame.h"
      
GameFactory::GameFactory() {
    reg_game(1, &TblGame1::create);
    reg_game(2, &TblGame2::create);
    reg_game(3, &TrGame::create);
}
GameFactory * GameFactory::get() {
    static GameFactory singleton;
    return &singleton;
}
void GameFactory::reg_game(const uint32_t & type, create_game_fn func) {
    game_map[type] = func;
}
Game * GameFactory::create_instance(const uint32_t & type) const {
	auto search = game_map.find(type);
    if (search != game_map.end())
    	return search -> second();
    return NULL;
}
