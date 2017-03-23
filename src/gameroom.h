#ifndef GAMESERVER_H
#define GAMESERVER_H

#include <vector>
#include <cstdint>

#include "player.h"
#include "languageservice.h"
#include "printer.h"

class GameRoom {
  protected:
    LanguageService * m_Console;
    Printer * m_Printer;
    uint32_t m_WordLen;
    std::vector<GameSession *> m_GameSessions;
    LanguageService & console() { return *m_Console; }
    Printer & printer() { return *m_Printer; }
  public:
    GameRoom() : m_Console(NULL), m_Printer(NULL),
                   m_WordLen(0) {}
    virtual ~GameRoom();
    void set_console(LanguageService * console) { m_Console = console; }
    void add_session(GameSession * session) { m_GameSessions.push_back(session); }
    void set_printer(Printer * printer) { m_Printer = printer; }
    void set_wordlen(const uint32_t & wordlen) { m_WordLen = wordlen; }
    virtual void launch();
    static GameRoom * create() { return new GameRoom(); }

};

#endif
