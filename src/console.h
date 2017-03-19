#ifndef CONSOLE_H
#define CONSOLE_H

#include <set>

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
    std::set<std::string> m_WordSet;
    void set_wordset(const std::set<std::string> & wordset) {
        m_WordSet = wordset;
    }
  public:
    Console(std::ostream & out) : m_Out(out), m_Game(NULL), m_WordLen() {}
    virtual ~Console() { reset(); }
    std::ostream & out() { return m_Out; }
    void set_setup(const std::string & setup);
    virtual void start() = 0;
    const std::string & setup() const { return m_Setup; }
    const uint32_t & wordlen() const { return m_WordLen; }
    void print_lang() const;
    void reset() { delete m_Game; }
    void set_wordlen(uint32_t val) { m_WordLen = val; }
    void load(const uint32_t & game_mode);
    bool play(const Strategy & strategy) const { return game().play(strategy); } 
};

#endif
