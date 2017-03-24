#include "filelanguageservice.h"
#include "langreader.h"

void FileLanguageService::load(const std::string &langid, Language &lang, const uint32_t &wordlen) const {
    LangReader lreader;
    lreader.read(langid, lang);
}
