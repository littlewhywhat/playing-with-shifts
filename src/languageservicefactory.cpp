#include "languageservice.h"
#include "languageservicefactory.h"
#include "graphlanguageservice.h"
#include "filelanguageservice.h"
#include "rulelanguageservice.h"
#include "no3inrow.h"

LanguageServiceFactory::LanguageServiceFactory() {
    reg_console("-g", &GraphLanguageService::create);
    reg_console("-l", &FileLanguageService::create);
    reg_console("-b", &No3inRow::create);
}

LanguageServiceFactory * LanguageServiceFactory::get() {
    static LanguageServiceFactory singleton;
    return &singleton;
}

void LanguageServiceFactory::reg_console(const std::string & type, create_console_fn func) {
    console_map[type] = func;
}

LanguageService * LanguageServiceFactory::create_instance(const std::string & type) const {
    auto search = console_map.find(type);
    if (search != console_map.end())
        return search -> second();
    return NULL;
}
