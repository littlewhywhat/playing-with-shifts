#ifndef CONSOLE_H
#define CONSOLE_H

#include "game.h"
#include "language.h"
#include "strategy.h"

class Console {
  private:
    std::ostream & m_Out;
    Game * m_Game;
    uint32_t m_WordLen;
    Game & game() const { return *m_Game; }
  protected:
    std::string m_Setup;
    virtual void fill(Language & lang) = 0;
  public:
    Console(std::ostream & out) : m_Out(out), m_Game(NULL), m_WordLen() {}
    virtual ~Console() { reset(); }
    std::ostream & out() { return m_Out; }
    void set_setup(const std::string & setup); 
    const std::string & setup() const { return m_Setup; }
    const uint32_t & wordlen() const { return game().wordlen(); }
    const Language & lang() const { return game().lang(); }
    void reset() { delete m_Game; }
    void set_wordlen(uint32_t val) { m_WordLen = val; }
    void load(const uint32_t & game_mode, const uint32_t & wordlen); 
    void load(const uint32_t & game_mode) { load(game_mode, m_WordLen); }
    bool play(const Strategy & strategy) const { return game().play(strategy); } 
};

#endif
