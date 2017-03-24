//
// Created by vaivorom on 3/23/17.
//

#include "gameserverservice.h"
#include "gameserver.h"

void GameServerService::launch(const std::vector<uint32_t> &modes, const std::vector<std::string> &what_tags,
                               const std::string &player_tag, const uint32_t &wordlen) {
    GameServer server;
    for (uint32_t i = 0; i < what_tags.size(); i += 2) {
        GameRoom * gs = AppContext::get().get_gameroom_service()
                .create(what_tags[i], what_tags[i + 1], modes, player_tag, wordlen);
        server.add_room(gs);
    }
    server.launch();
}
