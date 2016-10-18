#include "console.h"
#include "consolefactory"
#include "graphconsole.h"
#include "langconsole.h"
#include "buildconsole.h"

ConsoleFactory::ConsoleFactory() {
    reg_console("-g", &GraphConsole::create);
    reg_console("-l", &LangConsole::create);
    reg_console("-b", &BuildConsole::create);
}

static ConsoleFactory * ConsoleFactory::get() {
    static ConsoleFactory singleton;
    return &singleton;
}

void ConsoleFactory::reg_console(const std::string & type, create_console_fn func) {
    console_map[type] = func;
}

Console * create_instance(const std::string & type, std::ostream & out) const {
    auto search = console_map.find(type);
    if (search != console_map.end())
        return search -> second(out);
    return NULL;
}
