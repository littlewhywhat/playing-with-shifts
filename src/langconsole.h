#ifndef LANGCONSOLE_H
#define LANGCONSOLE_H

#include <ostream>

#include "console.h"

class LangConsole : public Console {
  private:
  public:
    LangConsole() : Console() {}
    std::set<std::string> start(const uint32_t & wordlen) override;
    static Console * create() { return new LangConsole(); }
};

#endif
