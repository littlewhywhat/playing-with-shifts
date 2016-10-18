#ifndef DIFFSERVER_H
#define DIFFSERVER_H

#include <vector>
#include <cstdint>

#include "player.h"
#include "console.h"
#include "gameserver.h"

class DiffServer : public GameServer {
  private:
    uint32_t process_mode(const uint32_t & game_mode);
 public:
    DiffServer() : GameServer() {}  
    DiffServer(Console * console, Player * player, const std::vector<uint32_t> & game_modes) :
        GameServer(console, player, game_modes) {}
    void launch() override; 
    static GameServer * create() { return new DiffServer(); }
};

#endif
