#ifndef LANGBUILDER_H
#define LANGBUILDER_H

#include "language.h"

class LangBuilder {
  protected:
    virtual bool is_relevant(uint64_t comb, const uint32_t & wordlen) const = 0;
  public:
    virtual ~LangBuilder() {};
    void build(Language & lang) const;
 };

#endif
