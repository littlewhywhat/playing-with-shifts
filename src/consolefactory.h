#ifndef CONSOLEFACTORY_H
#define CONSOLEFACTORY_H

#include <cstdint>

#include "console.h"
#include "graphconsole.h"
#include "langconsole.h"
#include "buildconsole.h"

class ConsoleFactory {
  private:
    ConsoleFactory() {
    	reg_console("-g", &GraphConsole::create);
    	reg_console("-l", &LangConsole::create);
    	reg_console("-b", &BuildConsole::create);
    }
    ConsoleFactory(const ConsoleFactory & src) = delete;
    ConsoleFactory & operator = (const ConsoleFactory & src) = delete;
    typedef Console* (*create_console_fn)(std::ostream & out);
    std::map<std::string, create_console_fn> console_map;
  public:
    ~ConsoleFactory() {};

    static ConsoleFactory * get() {
        static ConsoleFactory singleton;
        return &singleton;
    }

    void reg_console(const std::string & type, create_console_fn func) {
    	console_map[type] = func;
    }
    Console * create_instance(const std::string & type, std::ostream & out) const {
    	auto search = console_map.find(type);
    	if (search != console_map.end())
    		return search -> second(out);
    	return NULL;
    }
};

#endif
