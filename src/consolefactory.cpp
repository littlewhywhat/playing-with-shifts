#include "console.h"
#include "consolefactory.h"
#include "graphconsole.h"
#include "langconsole.h"
#include "buildconsole.h"

ConsoleFactory::ConsoleFactory() {
    reg_console("-g", &GraphConsole::create);
    reg_console("-l", &LangConsole::create);
    reg_console("-b", &BuildConsole::create);
}

ConsoleFactory * ConsoleFactory::get() {
    static ConsoleFactory singleton;
    return &singleton;
}

void ConsoleFactory::reg_console(const std::string & type, create_console_fn func) {
    console_map[type] = func;
}

Console * ConsoleFactory::create_instance(const std::string & type) const {
    auto search = console_map.find(type);
    if (search != console_map.end())
        return search -> second();
    return NULL;
}
