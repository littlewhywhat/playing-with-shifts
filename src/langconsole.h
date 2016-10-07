#ifndef LANGCONSOLE_H
#define LANGCONSOLE_H

#include <iostream>

#include "console.h"
#include "language.h"
#include "langbuilder.h"
#include "langbuilderfactory.h"
#include "utils.h"

class LangConsole : public Console {
  private:
    LangBuilder * m_LangBuilder;
    LangBuilder & langbuilder() {
        return *m_LangBuilder;
    }
    void fill(Language & lang) override {
        langbuilder().build(lang);
    }
  public:
    LangConsole(std::ostream & out) : Console(out), m_LangBuilder(NULL) {}
    ~LangConsole() {
        delete m_LangBuilder;
    }
    void set_langbuilder(const std::string & tag) {
        m_LangBuilder = LangBuilderFactory::get() -> create_instance(tag);
    }
};

#endif
