#include "filelanguageservice.h"
#include "langreader.h"

void FileLanguageService::load(Language &lang, const std::uint32_t &wordlen) {
    LangReader lreader;
    lreader.read(setup(), lang);
}
