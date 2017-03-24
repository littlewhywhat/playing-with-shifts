//
// Created by littlewhywhat on 3/24/17.
//

#ifndef SHIFTS_REALLANGUAGESERVICE_H
#define SHIFTS_REALLANGUAGESERVICE_H


#include <string>
#include "language.h"
#include "languageservicefactory.h"

class RealLanguageService {
  public:
    void load(const std::string & hostid, const std::string & lang_id,
              Language & lang, const uint32_t & wordlen) const {
        LanguageService * service = LanguageServiceFactory::get()->create_instance(hostid);
        if (!service)
            throw "no such lang service";
        service->load(lang_id, lang, wordlen);
    }
};


#endif //SHIFTS_REALLANGUAGESERVICE_H
