#include "buildconsole.h"
#include "langbuilderfactory.h"

void BuildConsole::start(Language & lang, const uint32_t & wordlen) {
    std::set<std::string> wordset;
    auto langbuilder = LangBuilderFactory::get() -> create_instance(setup());
    //TODO add check for NULL
    (*langbuilder).build(wordlen, lang);
    delete langbuilder;
}
