#ifndef CONSOLE_H
#define CONSOLE_H

#include "game.h"
#include "gamefactory.h"
#include "worddata.h"
#include "strategy.h"

class Console {
  private:
    std::ostream & m_Out;
    Game * m_Game;
    Game & game() const {
        return *m_Game;
    }
  protected:
    virtual void fill(WordData & wd) = 0;
  public:
    Console(std::ostream & out) : m_Out(out) {}
    virtual ~Console() {
        delete m_Game;
    }
    std::ostream & out() {
        return m_Out;
    }
    const uint32_t & wordlen() const {
        return game().wordlen();
    }
    const WordData & wd() const {
        return game().wd();
    }
    void load(const uint32_t & game_mode, const uint32_t & wordlen) {
        m_Game = GameFactory::get() -> create_instance(game_mode, wordlen);
        fill(game().wd());
    }
    bool play(const Strategy & strategy) const {
        return game().play(strategy);
    }
};

#endif
