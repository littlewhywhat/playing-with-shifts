#include "language.h"
#include "langconsole.h"
#include "langreader.h"

void LangConsole::start() {
    LangReader lreader;
    lreader.read(setup(), m_WordSet);
}
