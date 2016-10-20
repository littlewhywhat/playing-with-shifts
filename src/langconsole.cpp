#include "language.h"
#include "langconsole.h"
#include "langreader.h"

void LangConsole::fill(Language & lang) {
    LangReader lreader;
    lreader.read(lang, m_Setup);
}
