#include <vector>
#include <cstdint>

#include "graph.h"
#include "gnode.h"

Graph::~Graph() {
    for (GNode * node : m_Nodes)
        delete node;
}
void Graph::setSize(const uint32_t & size) {
    for (uint32_t i = 0; i < size; i++)
        m_Nodes.push_back(new GNode(i));
}
void Graph::addEdge(const uint32_t & from, const uint32_t & to, const char & label) {
    m_Nodes.at(from) -> add_out(m_Nodes.at(to), label);
}
