#include <vector>
#include <cstdint>
#include <iostream>

#include "player.h"
#include "console.h"
#include "gameserver.h"

uint32_t DiffServer::process_mode(const uint32_t & game_mode) {
    console().reset();
    console().load(game_mode);
    player().play(console());
    uint32_t score = player().score();
    std::cout << "mode: " <<  game_mode 
              << " results: " << score << std::endl;
    return score;
}
void DiffServer::launch() override {
    uint32_t score_0 = process_mode(m_GameModes[0]);
    for (uint32_t i = 1; i < m_GameModes.size(); i++) { 
        uint32_t score_i = process_mode(m_GameModes[i]);
        if (score_0 != score_i) {
            uint32_t diff = score_0 > score_i ? 
                            score_0 - score_i : 
                            score_i - score_0;
            std::cout << "setup: " << console().setup() << std::endl
                      << "difference: " << diff << std::endl;
        }
    }
}
