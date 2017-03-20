#include "graphconsole.h"
#include "graph.h"
#include "graph2lang.h"
#include "greader.h"
#include "language.h"
    

std::set<std::string> GraphConsole::start(const uint32_t & wordlen) {
    Graph graph;
    GReader greader;
    greader.read(graph, setup());
    Graph2Lang g2l;
    return g2l.translate(graph, wordlen);
}


