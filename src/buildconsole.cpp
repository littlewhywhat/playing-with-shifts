#include "buildconsole.h"
#include "language.h"
#include "langbuilderfactory.h"

void BuildConsole::start() {
    auto langbuilder = LangBuilderFactory::get() -> create_instance(setup());
    (*langbuilder).build(wordlen(), m_WordSet);
    delete langbuilder;
}
