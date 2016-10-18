#ifndef GAMEFACTORY_H
#define GAMEFACTORY_H

#include <cstdint>

#include "game.h"

class GameFactory {
  private:
    GameFactory();
    GameFactory(const GameFactory & src) = delete;
    GameFactory & operator = (const GameFactory & src) = delete;
    typedef Game* (*create_game_fn)(const uint32_t & wordlen);
    std::map<uint32_t, create_game_fn> game_map;
  public:
    ~GameFactory() {};

    static GameFactory * get();
    void reg_game(const uint32_t & type, create_game_fn func);
    
    Game * create_instance(const uint32_t & type, const uint32_t & wordlen) const 
};

#endif
