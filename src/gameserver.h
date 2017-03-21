#ifndef GAMESERVER_H
#define GAMESERVER_H

#include <vector>
#include <cstdint>

#include "player.h"
#include "console.h"
#include "printer.h"

class GameServer {
  protected:
    Language m_Language;
    Console * m_Console;
    Printer * m_Printer;
    uint32_t m_WordLen;
    std::vector<GameSession *> m_GameSessions;
    Console & console() { return *m_Console; }
    Printer & printer() { return *m_Printer; }
    Language & get_lang() { return m_Language; }
  public:
    GameServer() : m_Console(NULL), m_Printer(NULL),
                   m_WordLen(0) {}
    virtual ~GameServer();
    void set_console(Console * console) { m_Console = console; }
    void add_session(GameSession * session) { m_GameSessions.push_back(session); }
    void set_printer(Printer * printer) { m_Printer = printer; }
    void set_wordlen(const uint32_t & wordlen) { m_WordLen = wordlen; }
    virtual void launch();
    static GameServer * create() { return new GameServer(); }

};

#endif
