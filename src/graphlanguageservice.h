#ifndef GRAPHCONSOLE_H
#define GRAPHCONSOLE_H

#include "languageservice.h"

class GraphLanguageService : public LanguageService {
  public:
    GraphLanguageService() : LanguageService() {};
    void load(Language &lang, const uint32_t &wordlen) override;
    static LanguageService * create() { return new GraphLanguageService();}

};

#endif
