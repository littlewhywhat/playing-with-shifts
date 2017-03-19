#ifndef LANGCONSOLE_H
#define LANGCONSOLE_H

#include <ostream>

#include "console.h"
#include "language.h"

class LangConsole : public Console {
  private:
  public:
    LangConsole(std::ostream & out) : Console(out) {}
    void start() override;
    static Console * create(std::ostream & out) { return new LangConsole(out); }
};

#endif
