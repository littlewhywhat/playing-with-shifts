#ifndef BUILDCONSOLE_H
#define BUILDCONSOLE_H

#include <ostream>

#include "console.h"
#include "langbuilder.h"
#include "language.h"

class BuildConsole : public Console {
  private:
    LangBuilder * m_LangBuilder;
    LangBuilder & langbuilder() { return *m_LangBuilder; }
    void fill(Language & lang) override;
    void set_langbuilder(const std::string & tag);
  public:
    BuildConsole(std::ostream & out) : Console(out), m_LangBuilder(NULL) {}
    ~BuildConsole() { delete m_LangBuilder; }
    static Console * create(std::ostream & out) {
        return new BuildConsole(out);
    }
};

#endif
