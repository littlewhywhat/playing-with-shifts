#ifndef CONSOLEFACTORY_H
#define CONSOLEFACTORY_H

#include <map>

#include "languageservice.h"

class LanguageServiceFactory {
  private:
    LanguageServiceFactory();
    LanguageServiceFactory(const LanguageServiceFactory & src) = delete;
    LanguageServiceFactory & operator = (const LanguageServiceFactory & src) = delete;
    typedef LanguageService* (*create_console_fn)();
    std::map<std::string, create_console_fn> console_map;
  public:
    ~LanguageServiceFactory() {};
    static LanguageServiceFactory * get();
    void reg_console(const std::string & type, create_console_fn func); 
    LanguageService * create_instance(const std::string & type) const;
};

#endif
