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
    std::string player_tag;
    if (bundle.has_tag_in_strvec(TAG_PLAYER))
        player_tag = bundle.get_str(TAG_PLAYER);
    else
        player_tag = "success";
    std::string path;
    std::string langservice_tag;
    if (bundle.has_tag_in_strvec(TAG_GRAPH_PATHS)) {
        path = bundle.get_str(TAG_GRAPH_PATHS);
        langservice_tag = "-g"; 
    } else if (bundle.has_tag_in_strvec(TAG_LANG_PATHS)) {
        path = bundle.get_str(TAG_LANG_PATHS);
        langservice_tag = "-l";
    } else if (bundle.has_tag_in_strvec(TAG_BUILD_PATHS)) {
        path = bundle.get_str(TAG_BUILD_PATHS);
        langservice_tag = "-b";
    } else {
        // missing parameter
        return;
    }
    GameRoom *gr = AppContext::get().get_gameroom_service()
                .create(langservice_tag, path, modes, player_tag, wordlen);
    server.add_room(gr);
    server.launch();
}
