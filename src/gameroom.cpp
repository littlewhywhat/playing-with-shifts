#include "gameroom.h"
#include "gamefactory.h"
#include "judge.h"
#include "gamesession.h"

void GameRoom::launch() {
    Language lang;
    m_LangService.load(m_HostId, m_LangId, lang, m_WordLen);
    m_Printer.send_to_print(lang);
    for (auto * session : m_GameSessions) {
        session -> run(lang);
        if (has_filter() && !m_Filter->accepts(*session))
            continue;
        m_Printer.send_to_print(*session);
    }
}

GameRoom::~GameRoom() {
    for (auto & session : m_GameSessions)
        delete session;
}
