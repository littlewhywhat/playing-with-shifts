//
// Created by vaivorom on 3/23/17.
//

#ifndef PLAYING_WITH_SHIFTS_GAMESERVERSERVICE_H
#define PLAYING_WITH_SHIFTS_GAMESERVERSERVICE_H


#include <cstdint>
#include <vector>
#include <string>
#include "bundle.h"

class GameServer;

class GameServerService {
  public:
    static const std::string TAG_MODES;
    static const std::string TAG_GRAPH_PATHS;
    static const std::string TAG_LANG_PATHS;
    static const std::string TAG_BUILD_PATHS;
    static const std::string TAG_PLAYER;
    static const std::string TAG_WORDLEN;

    GameServerService() {}

    void launch(const Bundle & bundle) const;
  private:
    void add_rooms_to_server(GameServer & server,
                             const Bundle & bundle,
                             const std::string & langservice_tag,
                             const std::string & tag,
                             const std::vector<uint32_t> & modes,
                             const uint32_t & wordlen,
                             const std::string & player_tag) const;
};


#endif //PLAYING_WITH_SHIFTS_GAMESERVERSERVICE_H
