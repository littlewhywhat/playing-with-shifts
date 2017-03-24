#include "graphlanguageservice.h"
#include "graph.h"
#include "graph2lang.h"
#include "greader.h"

void GraphLanguageService::load(const std::string &langid, Language &lang, const uint32_t &wordlen) const {
    Graph graph;
    GReader greader;
    greader.read(graph, langid);
    Graph2Lang g2l;
    g2l.translate(graph, lang, wordlen);
}


