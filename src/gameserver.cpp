#include "gameserver.h"

void GameServer::launch() {
    console().start();
    for (auto game_mode : m_GameModes) { 
        console().reset();
        console().load(game_mode);
        player().play(console());
    }
}
