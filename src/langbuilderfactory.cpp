#ifndef LANGBUILDERFACTORY_H
#define LANGBUILDERFACTORY_H

#include <cstdint>

#include "langbuilder.h"
#include "langbuilderfactory.h"
#include "no3inrow.h"

LangBuilderFactory::LangBuilderFactory() {
    reg_langbuilder("no3inrow", &No3inRow::create);
}
static LangBuilderFactory * LangBuilderFactory::get() {
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
