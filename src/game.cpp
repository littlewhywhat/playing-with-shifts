#include <cstdint>

#include "strategy.h"
#include "game.h"

void Game::load(const Language & words) {
    for (auto & word : words)
        lang().add(word);
}
