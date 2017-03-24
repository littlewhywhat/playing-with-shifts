#ifndef CONSOLE_H
#define CONSOLE_H

#include <set>
#include <string>
#include "language.h"

class LanguageService {
  public:
    LanguageService() {}
    virtual ~LanguageService() { }

    virtual void load(const std::string &langid, Language &lang, const uint32_t &wordlen) const = 0;
};

#endif
