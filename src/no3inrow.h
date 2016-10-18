#ifndef NO3INROW_H
#define NO3INROW_H

#include "langbuilder.h"

class No3inRow : public LangBuilder {
  public:
    bool is_relevant(uint64_t word, const uint32_t & wordlen) const override; 
    static LangBuilder * create() { return new No3inRow(); }
};

#endif
