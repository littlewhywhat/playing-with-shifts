#ifndef APP_H
#define APP_H

#include "gameroom.h"
#include "argsparser.h"

class App {
  private:
    ArgsParser & m_Args;
  public:
    App(ArgsParser & args) : m_Args(args) {}
    void run();
};
#endif
