#include "gameserver.h"
#include "gamefactory.h"
#include "judge.h"
#include "gamesession.h"

void GameServer::launch() {
    std::set<std::string> lang = console().start(m_WordLen);
    printer().send_to_print(lang);
    for (auto * session : m_GameSessions) {
        session -> run(lang);
        printer().send_to_print(*session);
    }
}

GameServer::~GameServer() {
    delete m_Printer;
    delete m_Console;
    for (auto & session : m_GameSessions)
        delete session;
}
