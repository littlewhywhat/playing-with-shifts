#ifndef GAME_H
#define GAME_H

#include <cstdint>
#include <set>

#include "strategy.h"
#include "wordstructure.h"

class Game {
  private:
    WordStructure * m_Lang;
  protected:
    virtual bool play_ch(const Strategy & s) const = 0;
    Game(WordStructure * lang) : m_Lang(lang) {}
    Game() : m_Lang(NULL) {}
    // TODO language should be always set during contruction. Better way?
    void set_lang(WordStructure * lang) { m_Lang = lang; }
  public:
    virtual ~Game() { delete m_Lang; };
    WordStructure & lang() const { return *m_Lang; };
    void reset() { m_Lang -> clear(); }
    void load(std::set<std::string> words);
    bool play(const Strategy & s) const;
};

#endif
