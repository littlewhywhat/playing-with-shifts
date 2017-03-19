#ifndef LANGBUILDER_H
#define LANGBUILDER_H

#include <set>

#include "language.h"

class LangBuilder {
  protected:
    virtual bool is_relevant(uint64_t comb, const uint32_t & wordlen) const = 0;
  public:
    virtual ~LangBuilder() {};
    void build(const uint32_t & wordlen, std::set<std::string> & set) const;
 };

#endif
