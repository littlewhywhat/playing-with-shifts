#ifndef GRAPH_H
#define GRAPH_H

#include "gnode.h"

class Graph {
  private:
    std::vector<GNode*> m_Nodes;
  public:
    Graph(uint32_t size) {
        for (uint32_t i = 0; i < size; i++)
            m_Nodes.push_back(new GNode(i));
    }
    ~Graph() {
        for (GNode * node : m_Nodes)
            delete node;
    }
    void addEdge(uint32_t from, uint32_t to, char label) {
        m_Nodes.at(from) -> add_out(m_Nodes.at(to), label);
    }
    const std::vector<GNode*> & nodes() const {
        return m_Nodes;
    }

};

#endif