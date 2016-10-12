#ifndef GRAPHCONSOLE_H
#define GRAPHCONSOLE_H

#include <cstdint>

#include "console.h"
#include "graph.h"
#include "graph2lang.h"
#include "greader.h"
#include "language.h"

class GraphConsole : public Console {
  public:
    GraphConsole(std::ostream & out) : Console(out) {};
    GraphConsole(std::ostream & out, const std::string & graphfile) : 
            GraphConsole(out) {
        set_setup(graphfile);
    };
    void fill(Language & lang) override {
        Graph graph;
        GReader greader;
        greader.read(graph, m_Setup);
        Graph2Lang g2l;
        g2l.translate(graph, lang);
    }
    static Console * create(std::ostream & out) {
        return new GraphConsole(out);
    }
};

#endif
