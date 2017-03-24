#ifndef GAMESERVER_H
#define GAMESERVER_H

#include <vector>
#include <cstdint>

#include "player.h"
#include "languageservice.h"
#include "printer.h"
#include "appcontext.h"

class GameRoom {
  protected:
    std::string m_LangId;
    std::string m_HostId;
    const Printer & m_Printer;
    const RealLanguageService & m_LangService;
    uint32_t m_WordLen;
    std::vector<GameSession *> m_GameSessions;
    PlayedSessionFilter * m_Filter;
  public:
    GameRoom() : m_Printer(AppContext::get().get_printer()),
                 m_LangService(AppContext::get().get_language_service()),
                 m_WordLen(0), m_Filter(NULL) {}
    virtual ~GameRoom();
    void add_session(GameSession * session) { m_GameSessions.push_back(session); }
    void set_langid(const std::string & langid) { m_LangId = langid; }
    void set_hostid(const std::string & hostid) { m_HostId = hostid; }
    void set_wordlen(const uint32_t & wordlen) { m_WordLen = wordlen; }
    void set_filter(PlayedSessionFilter * filter) { m_Filter = filter; }
    bool has_filter() const { return m_Filter != NULL; }
    void launch();
    static GameRoom * create() { return new GameRoom(); }

};

#endif
