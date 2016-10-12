#ifndef LANGCONSOLE_H
#define LANGCONSOLE_H

#include <string>
#include <ostream>

#include "console.h"
#include "language.h"
#include "langreader.h"

class LangConsole : public Console {
  private:
  public:
    LangConsole(std::ostream & out) : Console(out) {}
    void fill(Language & lang) override {
        LangReader lreader;
        lreader.read(lang, m_Setup);
    }
    static Console * create(std::ostream & out) {
        return new LangConsole(out);
    }
};

#endif
