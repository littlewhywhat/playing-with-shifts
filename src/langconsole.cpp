#include "langconsole.h"
#include "langreader.h"

void LangConsole::start(Language & lang, const std::uint32_t & wordlen) {
    LangReader lreader;
    lreader.read(setup(), lang);
}
