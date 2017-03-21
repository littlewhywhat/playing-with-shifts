#include <cstdint>

#include "strategy.h"
#include "game.h"

bool Game::play(const Strategy & s) const {
    return play_ch(s);
}

void Game::load(const Language & words) {
    for (auto & word : words)
        lang().add(word);
}
