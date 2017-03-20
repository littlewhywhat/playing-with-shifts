#include "language.h"
#include "langconsole.h"
#include "langreader.h"

std::set<std::string> LangConsole::start(const std::uint32_t & wordlen) {
    LangReader lreader;
    std::set<std::string> wordset;
    lreader.read(setup(), wordset);
    return wordset;
}
