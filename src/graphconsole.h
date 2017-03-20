#ifndef GRAPHCONSOLE_H
#define GRAPHCONSOLE_H

#include "console.h"
#include "language.h"

class GraphConsole : public Console {
  public:
    GraphConsole() : Console() {};
    std::set<std::string> start(const uint32_t &wordlen) override;
    static Console * create() { return new GraphConsole();}

};

#endif
