#ifndef LANGCONSOLE_H
#define LANGCONSOLE_H

#include <ostream>

#include "languageservice.h"

class FileLanguageService : public LanguageService {
  private:
  public:
    FileLanguageService() : LanguageService() {}
    void load(Language &lang, const uint32_t &wordlen) override;
    static LanguageService * create() { return new FileLanguageService(); }
};

#endif
