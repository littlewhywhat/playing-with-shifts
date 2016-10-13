#ifndef APP_H
#define APP_H

#include <iostream>

#include "gameserver.h"
#include "argsparser.h"

class App {
  private:
    ArgsParser & m_Args;
  public:
    App(ArgsParser & args) : m_Args(args) {}
    void run() {
        try {
            for (GameServer * gs : m_Args.servers())
                gs -> launch();
        } catch (const char * e) {
            std::cout << e << std::endl;
        }
    }
};
#endif
