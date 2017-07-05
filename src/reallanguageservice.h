//
// Created by littlewhywhat on 3/24/17.
//

#ifndef SHIFTS_REALLANGUAGESERVICE_H
#define SHIFTS_REALLANGUAGESERVICE_H

#include <string>
#include <map>
#include "language.h"
#include "languageservice.h"

class RealLanguageService {
  private:
    std::map<std::string, LanguageService *> m_LangServices;
    const LanguageService &get_langservice(const std::string &hostid) const;
  public:
    RealLanguageService();
    ~RealLanguageService();
    void load(const std::string & hostid, const std::string & lang_id,
              Language & lang, const uint32_t & wordlen) const;
};


#endif //SHIFTS_REALLANGUAGESERVICE_H
