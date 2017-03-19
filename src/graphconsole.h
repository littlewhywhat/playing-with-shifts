#ifndef GRAPHCONSOLE_H
#define GRAPHCONSOLE_H

#include "console.h"
#include "language.h"

class GraphConsole : public Console {
  public:
    GraphConsole(std::ostream & out) : Console(out) {};
    void start() override;
    static Console * create(std::ostream & out) { return new GraphConsole(out);}

};

#endif
