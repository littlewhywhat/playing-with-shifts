#include "gameserver.h"
#include "gamefactory.h"
#include "judge.h"

void GameServer::launch() {
    std::set<std::string> lang = console().start(m_WordLen);
    printer().send_to_print(lang);
    for (auto & game_mode : m_GameModes) {
        //TODO Change m_GameModes to m_Games (extract Factory call)
        Game * game = GameFactory::get() -> create_instance(game_mode, m_WordLen);
        if (!game)
            throw "No such game mode.";
        for (auto & word : lang)
            game -> add_word(word);
        Judge judge;
        Player & player = get_player();
        judge.announce_to(printer());
        while (player.has_next()) {
            Strategy strategy = player.next_strategy(judge.current_score());
            if (judge.run(*game, strategy))
                printer().send_to_print(strategy);
        }
        judge.print_score_to(printer());
        player.reset();
        judge.reset();
        delete game;
    }
}
