#ifndef CONSOLE_H
#define CONSOLE_H

#include "game.h"
#include "gamefactory.h"
#include "language.h"
#include "strategy.h"

class Console {
  private:
    std::ostream & m_Out;
    Game * m_Game;
    Game & game() const {
        return *m_Game;
    }
  protected:
    virtual void fill(Language & lang) = 0;
  public:
    Console(std::ostream & out) : m_Out(out), m_Game(NULL) {}
    virtual ~Console() {
        reset();
    }
    std::ostream & out() {
        return m_Out;
    }
    const uint32_t & wordlen() const {
        return game().wordlen();
    }
    const Language & lang() const {
        return game().lang();
    }
    void reset() {
        delete m_Game;
    }
    void load(const uint32_t & game_mode, const uint32_t & wordlen) {
        m_Game = GameFactory::get() -> create_instance(game_mode, wordlen);
        fill(game().lang());
    }
    bool play(const Strategy & strategy) const {
        return game().play(strategy);
    }
};

#endif
