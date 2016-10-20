#ifndef LANGBUILDERFACTORY_H
#define LANGBUILDERFACTORY_H

#include <map>

#include "langbuilder.h"


class LangBuilderFactory {
  private:
    LangBuilderFactory(); 
    LangBuilderFactory(const LangBuilderFactory & src) = delete;
    LangBuilderFactory & operator = (const LangBuilderFactory & src) = delete;
    typedef LangBuilder* (*create_lbuilder_fn)();
    std::map<std::string, create_lbuilder_fn> lbuilder_map;
  public:
    ~LangBuilderFactory() {};

    static LangBuilderFactory * get(); 

    void reg_langbuilder(const std::string & tag, create_lbuilder_fn func); 
    LangBuilder * create_instance(const std::string & tag) const;
};

#endif
