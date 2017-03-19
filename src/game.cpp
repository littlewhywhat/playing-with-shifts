#include <cstdint>

#include "strategy.h"
#include "game.h"

void Game::add_word(const std::string &word) {
    lang().add(word);
}

bool Game::play(const Strategy & s) const {
    return play_ch(s);
}
