#include <cstdint>

#include "strategy.h"
#include "game.h"

bool Game::play(const Strategy & s) const {
    if (!has_lang())
        throw "Language wasn't set!";
    return play_ch(s); 
}
