#ifndef GRAPH2WT_H
#define GRAPH2WT_H

#include <string>
#include <set>
#include <cstdint>

#include "graph.h"
#include "language.h"

class Graph2Lang {
  private:
    void produceNext(std::set<std::string> & wordset, Language & lang, const GNode * node, uint32_t lettercnt, std::string & buffer) const;
  public:
    void translate(const Graph & graph, Language & lang) const;
};

#endif
