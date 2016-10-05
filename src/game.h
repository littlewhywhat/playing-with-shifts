#ifndef GAME_H
#define GAME_H

#include <cstdint>

#include "strategy.h"

class WordData;

class Game {
  protected:
    virtual bool has_wd() const = 0;
    virtual bool play_ch(const Strategy & s) const = 0;
  public:
    virtual ~Game() {};
    virtual WordData & wd() const = 0;
    virtual const uint32_t & wordlen() const = 0;
    bool play(const Strategy & s) const {
        if (!has_wd())
            throw "WordData wasn't set!";
        return play_ch(s); 
    }
};

#endif
