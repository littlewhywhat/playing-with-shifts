#ifndef GRAPHCONSOLE_H
#define GRAPHCONSOLE_H

#include <cstdint>

#include "console.h"
#include "graph.h"
#include "graph2wd.h"
#include "greader.h"
#include "worddata.h"

class GraphConsole : public Console {
  private:
    const std::string m_GraphFile;
  public:
    GraphConsole(std::ostream & out, const std::string & graphfile) : 
            Console(out), m_GraphFile(graphfile) {};
    void fill(WordData & wd) override {
        Graph graph;
        GReader greader(m_GraphFile);
        greader.read(graph);
        Graph2Wd g2wd;
        g2wd.translate(graph, wd);
    }
};

#endif
