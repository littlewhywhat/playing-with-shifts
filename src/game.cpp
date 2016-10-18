#include <cstdint>

#include "strategy.h"

bool Game::play(const Strategy & s) const {
    if (!has_lang())
        throw "Language wasn't set!";
    return play_ch(s); 
}
