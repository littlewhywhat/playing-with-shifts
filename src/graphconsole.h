#ifndef GRAPHCONSOLE_H
#define GRAPHCONSOLE_H

#include "console.h"

class GraphConsole : public Console {
  public:
    GraphConsole() : Console() {};
    void start(Language & lang, const uint32_t &wordlen) override;
    static Console * create() { return new GraphConsole();}

};

#endif
