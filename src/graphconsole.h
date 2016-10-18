#ifndef GRAPHCONSOLE_H
#define GRAPHCONSOLE_H

#include "console.h"
#include "language.h"

class GraphConsole : public Console {
  public:
    GraphConsole(std::ostream & out) : Console(out) {};
    GraphConsole(std::ostream & out, const std::string & graphfile) : 
            GraphConsole(out) { set_setup(graphfile); }
    void fill(Language & lang) override;
    static Console * create(std::ostream & out) { return new GraphConsole(out);}
};

#endif
