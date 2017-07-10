//
// Created by vaivorom on 3/23/17.
//

#include "gameserverservice.h"
#include "gameserver.h"

const std::string GameServerService::TAG_MODES = "modes";
const std::string GameServerService::TAG_GRAPH_PATHS = "graph_paths";
const std::string GameServerService::TAG_LANG_PATHS = "lang_paths";
const std::string GameServerService::TAG_BUILD_PATHS = "build_paths";
const std::string GameServerService::TAG_PLAYER = "player";
const std::string GameServerService::TAG_WORDLEN = "wordlen";

void GameServerService::launch(const Bundle & bundle) const {
    GameServer server;
    const std::vector<uint32_t> & modes = bundle.get_intvector(TAG_MODES);
    const std::uint32_t & wordlen = bundle.get_int(TAG_WORDLEN);
    std::string player;
    if (bundle.has_tag_in_strvec(TAG_PLAYER))
        player = bundle.get_str(TAG_PLAYER);
    else
        player = "success";
    add_rooms_to_server(server, bundle, "-g", TAG_GRAPH_PATHS, modes, wordlen, player);
    add_rooms_to_server(server, bundle, "-b", TAG_BUILD_PATHS, modes, wordlen, player);
    add_rooms_to_server(server, bundle, "-l", TAG_LANG_PATHS, modes, wordlen, player);
    server.launch();
}

void
GameServerService::add_rooms_to_server(GameServer &server, const Bundle &bundle, const std::string &langservice_tag,
                                       const std::string &tag, const std::vector<uint32_t> &modes,
                                       const uint32_t &wordlen, const std::string &player_tag) const {
    if (bundle.has_tag_in_strvec(tag)) {
        const std::string & path = bundle.get_str(tag);
        GameRoom *gs = AppContext::get().get_gameroom_service()
                    .create(langservice_tag, path, modes, player_tag, wordlen);
        server.add_room(gs);
    }
}
