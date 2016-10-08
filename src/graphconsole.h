#ifndef GRAPHCONSOLE_H
#define GRAPHCONSOLE_H

#include <cstdint>

#include "console.h"
#include "graph.h"
#include "graph2lang.h"
#include "greader.h"
#include "language.h"

class GraphConsole : public Console {
  private:
    std::string m_GraphFile;
  public:
    GraphConsole(std::ostream & out) : Console(out) {};
    GraphConsole(std::ostream & out, const std::string & graphfile) : 
            GraphConsole(out) {
        set_graphfile(graphfile);
    };
    void set_graphfile(const std::string & graphfile) {
        m_GraphFile = graphfile;
    }
    const std::string & graphfile() const {
        return m_GraphFile;
    }
    void fill(Language & lang) override {
        Graph graph;
        GReader greader;
        greader.read(graph, m_GraphFile);
        Graph2Lang g2l;
        g2l.translate(graph, lang);
    }
};

#endif
