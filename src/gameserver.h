#ifndef GAMESERVER_H
#define GAMESERVER_H

#include <vector>
#include <cstdint>

#include "player.h"
#include "console.h"

class GameServer {
  protected:
    Console & m_Console;
    Player & m_Player;
    const std::vector<uint32_t> & m_GameModes;
  public:
    GameServer(Console & console, Player & player, const std::vector<uint32_t> & game_modes) :
        m_Console(console), m_Player(player), m_GameModes(game_modes) {}
    virtual void launch() {
        for (auto game_mode : m_GameModes) { 
            m_Console.reset();
            m_Console.load(game_mode);
            m_Player.play(m_Console);
        }
    }
};

#endif
