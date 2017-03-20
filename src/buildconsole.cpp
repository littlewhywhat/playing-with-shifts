#include "buildconsole.h"
#include "language.h"
#include "langbuilderfactory.h"

std::set<std::string> BuildConsole::start(const uint32_t & wordlen) {
    std::set<std::string> wordset;
    auto langbuilder = LangBuilderFactory::get() -> create_instance(setup());
    //TODO add check for NULL
    (*langbuilder).build(wordlen, wordset);
    delete langbuilder;
    return wordset;
}
