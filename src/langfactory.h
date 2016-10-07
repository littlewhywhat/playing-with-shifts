#ifndef LANGFACTORY_H
#define LANGFACTORY_H

#include <cstdint>

#include "language.h"
#include "no3inrow.h"

class LangFactory {
  private:
    LangFactory() {
    	reg_lang(1, &No3inRow::create);
    }
    LangFactory(const LangFactory & src) = delete;
    LangFactory & operator = (const LangFactory & src) = delete;
    typedef Lang* (*create_lang_fn)();
    std::map<uint32_t, create_lang> lang_map;
  public:
    ~LangFactory() {};

    static LangFactory * get() {
        static LangFactory singleton;
        return &singleton;
    }

    void reg_lang(const uint32_t & type, create_lang_fn func) {
    	lang_map[type] = func;
    }
    Lang * create_instance(const uint32_t & type, const uint32_t & wordlen) const {
    	auto search = lang_map.find(type);
    	if (search != lang_map.end())
    		return search -> second(wordlen);
    	return NULL;
    }
};

#endif
