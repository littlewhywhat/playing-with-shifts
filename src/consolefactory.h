#ifndef CONSOLEFACTORY_H
#define CONSOLEFACTORY_H

#include "console.h"

class ConsoleFactory {
  private:
    ConsoleFactory();
    ConsoleFactory(const ConsoleFactory & src) = delete;
    ConsoleFactory & operator = (const ConsoleFactory & src) = delete;
    typedef Console* (*create_console_fn)(std::ostream & out);
    std::map<std::string, create_console_fn> console_map;
  public:
    ~ConsoleFactory() {};
    static ConsoleFactory * get();
    void reg_console(const std::string & type, create_console_fn func); 
    Console * create_instance(const std::string & type, std::ostream & out) const;
};

#endif
