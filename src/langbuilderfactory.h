#ifndef LANGBUILDERFACTORY_H
#define LANGBUILDERFACTORY_H

#include <cstdint>

#include "langbuilder.h"
#include "no3inrow.h"

class LangBuilderFactory {
  private:
    LangBuilderFactory() {
    	reg_langbuilder("no3inrow", &No3inRow::create);
    }
    LangBuilderFactory(const LangBuilderFactory & src) = delete;
    LangBuilderFactory & operator = (const LangBuilderFactory & src) = delete;
    typedef LangBuilder* (*create_lbuilder_fn)();
    std::map<std::string, create_lbuilder_fn> lbuilder_map;
  public:
    ~LangBuilderFactory() {};

    static LangBuilderFactory * get() {
        static LangBuilderFactory singleton;
        return &singleton;
    }

    void reg_langbuilder(const std::string & tag, create_lbuilder_fn func) {
    	lbuilder_map[tag] = func;
    }
    LangBuilder * create_instance(const std::string & tag) const {
    	auto search = lbuilder_map.find(tag);
    	if (search != lbuilder_map.end())
    		return search -> second();
    	return NULL;
    }
};

#endif
