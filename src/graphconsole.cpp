#include "graphconsole.h"
#include "graph.h"
#include "graph2lang.h"
#include "greader.h"
#include "language.h"
    

void GraphConsole::start() {
    Graph graph;
    GReader greader;
    greader.read(graph, m_Setup);
    Graph2Lang g2l;
    g2l.translate(graph, wordlen(), m_WordSet);
}


