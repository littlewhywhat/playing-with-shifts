#ifndef LANGCONSOLE_H
#define LANGCONSOLE_H

#include <ostream>

#include "languageservice.h"

class FileLanguageService : public LanguageService {
  private:
  public:
    FileLanguageService() : LanguageService() {}
    void load(const std::string &langid, Language &lang, const uint32_t &wordlen) const override;
    static LanguageService * create() { return new FileLanguageService(); }
};

#endif
