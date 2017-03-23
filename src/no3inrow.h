#ifndef NO3INROW_H
#define NO3INROW_H

#include "rulelanguageservice.h"

class No3inRow : public RuleLanguageService {
  public:
    bool is_relevant(uint64_t word, const uint32_t & wordlen) const override; 
    static LanguageService * create() { return new No3inRow(); }
};

#endif
