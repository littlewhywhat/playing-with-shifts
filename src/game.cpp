#include <cstdint>

#include "strategy.h"
#include "game.h"

void Game::add_word(const std::string &word) {
    if (!has_lang())
        throw "Language wasn't set!";
    lang().add(word);
}

bool Game::play(const Strategy & s) const {
    if (!has_lang())
        throw "Language wasn't set!";
    return play_ch(s); 
}
