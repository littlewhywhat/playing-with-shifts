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
    Judge m_Judge;
    std::vector<Game *> m_Games;
    Console & console() { return *m_Console; }
    Player & get_player() { return *m_Player; }
    Printer & printer() { return *m_Printer; }
  public:
    GameServer() : m_Console(NULL), m_Player(NULL), m_Printer(NULL),
                   m_WordLen(0) {}
    virtual ~GameServer();
    void set_console(Console * console) { m_Console = console; }
    void set_player(Player * player) { m_Player = player; }
    void add_game(Game * game) { m_Games.push_back(game); }
    void set_printer(Printer * printer) { m_Printer = printer; }
    void set_wordlen(const uint32_t & wordlen) { m_WordLen = wordlen; }
    virtual void launch();
    static GameServer * create() { return new GameServer(); }

};

#endif
