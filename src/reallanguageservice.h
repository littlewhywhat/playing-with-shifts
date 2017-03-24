//
// Created by littlewhywhat on 3/24/17.
//

#ifndef SHIFTS_REALLANGUAGESERVICE_H
#define SHIFTS_REALLANGUAGESERVICE_H


#include <string>
#include <map>
#include "language.h"
#include "graphlanguageservice.h"
#include "filelanguageservice.h"
#include "no3inrow.h"

class RealLanguageService {
  private:
    std::map<std::string, LanguageService *> m_LangServices;
  public:
    RealLanguageService() {
        m_LangServices["-g"] = new GraphLanguageService();
        m_LangServices["-l"] = new FileLanguageService();
        m_LangServices["-b"] = new No3inRow();
    }
    ~RealLanguageService() {
        for (auto & service_entry : m_LangServices)
            delete service_entry.second;
    }

    const LanguageService &get_langservice(const std::string &hostid) const {
        if (m_LangServices.find(hostid) == m_LangServices.end())
            throw "no such lang service";
        auto & service_entry = *m_LangServices.find(hostid);
        return *service_entry.second;
    }

    void load(const std::string & hostid, const std::string & lang_id,
              Language & lang, const uint32_t & wordlen) const {
        const LanguageService & service = get_langservice(hostid);
        service.load(lang_id, lang, wordlen);
    }

};


#endif //SHIFTS_REALLANGUAGESERVICE_H
