#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <cstdint>

#include "gnode.h"

class Graph {
  private:
    std::vector<GNode*> m_Nodes;
  public:
    ~Graph();
    void setSize(const uint32_t & size);
    void addEdge(const uint32_t & from, const uint32_t & to, const char & label); 
    const std::vector<GNode*> & nodes() const { return m_Nodes; }
};

#endif
