#ifndef GRAPH2WT_H
#define GRAPH2WT_H

#include <string>
#include <set>
#include <cstdint>

#include "graph.h"

class Graph2Lang {
  private:
    void produceNext(std::set<std::string> & wordset, const uint32_t & wordlength, const GNode * node, uint32_t lettercnt, std::string & buffer) const;
  public:
    void translate(const Graph & graph, const uint32_t &wordlength, std::set<std::string> & set) const;
};

#endif
