//
// Created by vaivorom on 3/23/17.
//

#ifndef PLAYING_WITH_SHIFTS_GAMESERVERSERVICE_H
#define PLAYING_WITH_SHIFTS_GAMESERVERSERVICE_H


#include <cstdint>
#include <vector>
#include <string>

class GameServerService {
  public:
    GameServerService() {}

    void launch(const std::vector <uint32_t> & modes,
                const std::vector <std::string> & what_tags,
                const std::string & player_tag,
                const uint32_t & wordlen);

};


#endif //PLAYING_WITH_SHIFTS_GAMESERVERSERVICE_H
