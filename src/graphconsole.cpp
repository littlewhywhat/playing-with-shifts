#include "graphconsole.h"
#include "graph.h"
#include "graph2lang.h"
#include "greader.h"

void GraphConsole::start(Language & lang, const uint32_t & wordlen) {
    Graph graph;
    GReader greader;
    greader.read(graph, setup());
    Graph2Lang g2l;
    g2l.translate(graph, lang, wordlen);
}


