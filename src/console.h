#ifndef CONSOLE_H
#define CONSOLE_H

#include <set>
#include <string>
#include "language.h"

class Console {
  private:
    std::string m_Setup;
  public:
    Console() {}
    virtual ~Console() { }

    void set_setup(const std::string & setup) { m_Setup = setup; };
    const std::string & setup() const { return m_Setup; }

    virtual void start(Language & lang, const uint32_t &wordlen) = 0;
};

#endif
