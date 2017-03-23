#include "gameroom.h"
#include "gamefactory.h"
#include "judge.h"
#include "gamesession.h"

void GameRoom::launch() {
    Language lang;
    console().load(lang, m_WordLen);
    printer().send_to_print(lang);
    for (auto * session : m_GameSessions) {
        session -> run(lang);
        printer().send_to_print(*session);
    }
}

GameRoom::~GameRoom() {
    delete m_Printer;
    delete m_Console;
    for (auto & session : m_GameSessions)
        delete session;
}
