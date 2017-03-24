//
// Created by vaivorom on 3/23/17.
//

#ifndef PLAYING_WITH_SHIFTS_GAMESERVERSERVICE_H
#define PLAYING_WITH_SHIFTS_GAMESERVERSERVICE_H


#include "app.h"
#include "appcontext.h"
#include "gameserver.h"

class GameServerService {
  public:
    GameServerService() {}

    void launch(const std::vector <uint32_t> & modes,
                const std::vector <std::string> & what_tags,
                const uint32_t wordlen,
                const App & app) {
        for (uint32_t i = 0; i < what_tags.size(); i += 2) {

        }
    }

  private:

    const Printer & get_printer() const {
        return AppContext::get().get_printer();
    }
};


#endif //PLAYING_WITH_SHIFTS_GAMESERVERSERVICE_H
