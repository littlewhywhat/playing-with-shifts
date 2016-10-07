#ifndef LANGCONSOLE_H
#define LANGCONSOLE_H

#include <string>
#include <ostream>

#include "console.h"
#include "language.h"
#include "langreader.h"

class LangConsole : public Console {
  private:
    std::string m_LangFile;
  public:
    LangConsole(std::ostream & out, const std::string & langfile) : Console(out), m_LangFile(langfile) {}
    void fill(Language & lang) override {
        LangReader lreader;
        lreader.read(lang, m_LangFile);
    }
};

#endif
