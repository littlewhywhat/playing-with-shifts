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
    static const std::string TAG_NUM_PATHS;
    static const std::string TAG_FILE;

    GameServerService() {}

    void launch(const Bundle & bundle) const;
};


#endif //PLAYING_WITH_SHIFTS_GAMESERVERSERVICE_H
