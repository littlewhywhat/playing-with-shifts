#include "gameserver.h"
#include "gamefactory.h"
#include "judge.h"
#include "gamesession.h"

void GameServer::launch() {
    std::set<std::string> lang = console().start(m_WordLen);
    printer().send_to_print(lang);
    for (auto & game : m_Games) {
        GameSession session(*game, m_Judge, get_player());
        m_Judge.announce_to(printer());
        session.run(lang);
        printer().send_to_print(session.results());
    }
}

GameServer::~GameServer() {
    delete m_Console;
    delete m_Player;
    for (auto & game : m_Games)
        delete game;
}
