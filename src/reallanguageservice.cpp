//
// Created by littlewhywhat on 3/24/17.
//

#include "reallanguageservice.h"

#include "graphlanguageservice.h"
#include "filelanguageservice.h"
#include "no3inrow.h"

RealLanguageService::RealLanguageService() {
    m_LangServices["-g"] = new GraphLanguageService();
    m_LangServices["-l"] = new FileLanguageService();
    m_LangServices["-b"] = new No3inRow();
}

RealLanguageService::~RealLanguageService() {
    for (auto & service_entry : m_LangServices)
        delete service_entry.second;
}

const LanguageService & RealLanguageService::get_langservice(const std::string &hostid) const {
    if (m_LangServices.find(hostid) == m_LangServices.end())
        throw "no such lang service";
    auto & service_entry = *m_LangServices.find(hostid);
    return *service_entry.second;
}

void RealLanguageService::load(const std::string & hostid, const std::string & lang_id,
          Language & lang, const uint32_t & wordlen) const {
    const LanguageService & service = get_langservice(hostid);
    service.load(lang_id, lang, wordlen);
}
