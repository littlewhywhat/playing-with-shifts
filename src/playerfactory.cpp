#include <string>

#include "playerfactory.h"
#include "player.h"
#include "maxbcntplayer.h"
#include "langoutplayer.h"

PlayerFactory::PlayerFactory() {
    reg_player("player", &Player::create);
    reg_player("maxbcnt", &MaxBCntPlayer::create);
    reg_player("langout", &LangOutPlayer::create);
}

void PlayerFactory::reg_player(const std::string & type, create_player_fn func) {
    player_map[type] = func;
}
Player * PlayerFactory::create_instance(const std::string & type) const {
    auto search = player_map.find(type);
    if (search != player_map.end())
        return search -> second();
    return NULL;
}
