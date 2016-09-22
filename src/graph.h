#ifndef GRAPH_H
#define GRAPH_H

#include "gnode.h"

class Graph {
  private:
    std::vector<GNode*> m_Nodes;
  public:
    ~Graph() {
        for (GNode * node : m_Nodes)
            delete node;
    }
    void setSize(const uint32_t & size) {
        for (uint32_t i = 0; i < size; i++)
            m_Nodes.push_back(new GNode(i));
    }
    void addEdge(const uint32_t & from, const uint32_t & to, const char & label) {
        m_Nodes.at(from) -> add_out(m_Nodes.at(to), label);
    }
    const std::vector<GNode*> & nodes() const {
        return m_Nodes;
    }

};

#endif
