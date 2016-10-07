#ifndef GAME_H
#define GAME_H

#include <cstdint>

#include "strategy.h"

class Language;

class Game {
  protected:
    virtual bool has_lang() const = 0;
    virtual bool play_ch(const Strategy & s) const = 0;
  public:
    virtual ~Game() {};
    virtual Language & lang() const = 0;
    virtual const uint32_t & wordlen() const = 0;
    bool play(const Strategy & s) const {
        if (!has_lang())
            throw "Language wasn't set!";
        return play_ch(s); 
    }
};

#endif
