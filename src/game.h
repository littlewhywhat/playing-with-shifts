#ifndef GAME_H
#define GAME_H

#include <cstdint>

#include "strategy.h"
#include "language.h"

class Game {
  protected:
    virtual bool has_lang() const = 0;
    virtual bool play_ch(const Strategy & s) const = 0;
  public:
    virtual ~Game() {};
    virtual Language & lang() const = 0;
    virtual void add_word(const std::string & word) = 0;
    bool play(const Strategy & s) const;
};

#endif
