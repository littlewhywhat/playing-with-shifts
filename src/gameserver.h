#ifndef GAMESERVER_H
#define GAMESERVER_H

#include <vector>
#include <cstdint>

#include "player.h"
#include "console.h"
#include "printer.h"

class GameServer {
  protected:
    Console * m_Console;
    Player * m_Player;
    Printer * m_Printer;
    uint32_t m_WordLen;
    std::vector<uint32_t> m_GameModes;
    Console & console() { return *m_Console; }
    Player & get_player() { return *m_Player; }
    Printer & printer() { return *m_Printer; }
  public:
    GameServer() : m_Console(NULL), m_Player(NULL), m_Printer(NULL),
                   m_WordLen(0) {}
    GameServer(Console * console, Player * player, const std::vector<uint32_t> & game_modes) :
        m_Console(console), m_Player(player), m_GameModes(game_modes) {}
    virtual ~GameServer() { delete m_Console; delete m_Player; }
    void set_console(Console * console) { m_Console = console; }
    void set_player(Player * player) { m_Player = player; }
    void set_modes(const std::vector<uint32_t> & modes) { m_GameModes = modes; }
    void set_printer(Printer * printer) { m_Printer = printer; }
    void set_wordlen(const uint32_t & wordlen) { m_WordLen = wordlen; }
    virtual void launch();
    static GameServer * create() { return new GameServer(); }

};

#endif
