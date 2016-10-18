#include "language.h"
#include "langreader.h"

void LangReader::fill(Language & lang) override {
    LangReader lreader;
    lreader.read(lang, m_Setup);
}
