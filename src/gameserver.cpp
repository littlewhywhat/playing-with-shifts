#include "gameserver.h"
#include "gamefactory.h"
#include "judge.h"

void GameServer::launch() {
    std::set<std::string> lang = console().start(m_WordLen);
    printer().send_to_print(lang);
    for (auto & game : m_Games) {
        //TODO introduce GameSession class;
        //TODO pack results and replace printer calls to one post results
        game -> load(lang);
        Player & player = get_player();
        m_Judge.announce_to(printer());
        while (player.has_next()) {
            Strategy strategy = player.next_strategy(m_Judge.current_score());
            if (m_Judge.run(*game, strategy))
                printer().send_to_print(strategy);
        }
        m_Judge.print_score_to(printer());
        player.reset();
        m_Judge.reset();
        game -> reset();
    }
}

GameServer::~GameServer() {
    delete m_Console;
    delete m_Player;
    for (auto & game : m_Games)
        delete game;
}
