#ifndef BUILDCONSOLE_H
#define BUILDCONSOLE_H

#include <iostream>

#include "console.h"
#include "language.h"
#include "langbuilder.h"
#include "langbuilderfactory.h"
#include "utils.h"

class BuildConsole : public Console {
  private:
    LangBuilder * m_LangBuilder;
    std::string m_Tag;
    LangBuilder & langbuilder() {
        return *m_LangBuilder;
    }
    void fill(Language & lang) override {
        langbuilder().build(lang);
    }
  public:
    BuildConsole(std::ostream & out) : Console(out), m_LangBuilder(NULL), m_Tag(std::string()) {}
    ~BuildConsole() {
        delete m_LangBuilder;
    }
    void set_langbuilder(const std::string & tag) {
        m_LangBuilder = LangBuilderFactory::get() -> create_instance(tag);
        m_Tag = tag;
    }
    void print_info() const {
        out() << "tag: " << m_Tag << std::endl; 
    }
};

#endif
