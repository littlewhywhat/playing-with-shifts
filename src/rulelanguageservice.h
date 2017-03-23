#ifndef BUILDCONSOLE_H
#define BUILDCONSOLE_H

#include <ostream>

#include "languageservice.h"

class RuleLanguageService : public LanguageService {
  public:
    RuleLanguageService() : LanguageService() {}
    virtual bool is_relevant(uint64_t comb, const uint32_t & wordlen) const = 0;
    void load(Language &lang, const uint32_t &wordlen) override;
};

#endif
