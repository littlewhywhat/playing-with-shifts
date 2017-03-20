#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H

#include <string>
#include <map>

#include "player.h"

class PlayerFactory {
  private:
    PlayerFactory();
    PlayerFactory(const PlayerFactory & src) = delete;
    PlayerFactory & operator = (const PlayerFactory & src) = delete;
    typedef Player* (*create_player_fn)(const uint32_t & len);
    std::map<std::string, create_player_fn> player_map;
  public:
    ~PlayerFactory() {};

    static PlayerFactory * get() {
        static PlayerFactory singleton;
        return &singleton;
    }

    void reg_player(const std::string & type, create_player_fn func); 
    Player *create_instance(const std::string &type, const uint32_t &len) const;
};

#endif
