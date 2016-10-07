#ifndef LANGCONSOLE_H
#define LANGCONSOLE_H

#include <iostream>

#include "console.h"
#include "langbuilder.h"
#include "langbuilderfactory.h"
#include "worddata.h"
#include "utils.h"

class LangConsole : public Console {
  private:
    LangBuilder * m_LangBuilder;
    LangBuilder & langbuilder() {
        return *m_LangBuilder;
    }
    void fill(WordData & wd) override {
        langbuilder().build(wd);
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
