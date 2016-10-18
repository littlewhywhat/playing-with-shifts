#ifndef GAMESERVER_H
#define GAMESERVER_H

#include <vector>
#include <cstdint>

#include "player.h"
#include "console.h"

class GameServer {
  protected:
    Console * m_Console;
    Player * m_Player;
    std::vector<uint32_t> m_GameModes;
    Console & console() { return *m_Console; }
    Player & player() { return *m_Player; }
  public:
    GameServer() : m_Console(NULL), m_Player(NULL) {}
    GameServer(Console * console, Player * player, const std::vector<uint32_t> & game_modes) :
        m_Console(console), m_Player(player), m_GameModes(game_modes) {}
    virtual ~GameServer() { delete m_Console; delete m_Player; }
    void set_console(Console * console) { m_Console = console; }
    void set_player(Player * player) { m_Player = player; }
    void set_modes(const std::vector<uint32_t> & modes) { m_GameModes = modes; }
    virtual void launch();
    static GameServer * create() { return new GameServer(); }
};

#endif
