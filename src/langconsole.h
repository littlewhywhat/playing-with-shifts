#ifndef LANGCONSOLE_H
#define LANGCONSOLE_H

#include "worddata.h"
#include "utils.h"

class LangConsole : Console {
  private:
    Language * m_Lang;
    Language & lang() {
        return *m_Lang;
    }
    void fill(WordData & wd) {
        uint64_t max_comb = 1 << wd.wordlen();
        for (uint64_t comb = 0; comb < max_comb; comb++)
            if (lang().has(comb, wd.wordlen()))
                wd.add(i2s(comb, wd.wordlen()));
    }
  public:
    LangConsole(const std::string & subsh_name) {
        m_Lang = LangFactory::get() -> create_instance(subsh_name);
    }
};

#endif
