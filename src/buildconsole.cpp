#include "buildconsole.h"
#include "language.h"
#include "langbuilderfactory.h"

void BuildConsole::fill(Language & lang) {
    if (!m_LangBuilder)
        set_langbuilder(m_Setup);
    langbuilder().build(lang);
}
void BuildConsole::set_langbuilder(const std::string & tag) {
    m_LangBuilder = LangBuilderFactory::get() -> create_instance(tag);
}
