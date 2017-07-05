#ifndef GAME_H
#define GAME_H

#include <cstdint>
#include <set>

#include "strategy.h"
#include "wordstructure.h"
#include "language.h"

/*
 *  Plays strategy on the language.
 *  Language prior should be loaded in optimal datastructure.
 *  Abstract class.
 */
class Game {
  private:
    WordStructure * m_Lang;
  protected:
    Game(WordStructure * lang) : m_Lang(lang) {}
    Game() : m_Lang(NULL) {}
    // TODO language should be always set during contruction. Better way?
    void set_lang(WordStructure * lang) { m_Lang = lang; }
  public:
    virtual ~Game() { delete m_Lang; };
    WordStructure & lang() const { return *m_Lang; };
    void reset() { m_Lang -> clear(); }
    void load(const Language & words);
    virtual bool play(const Strategy & s) const = 0;
};

#endif
