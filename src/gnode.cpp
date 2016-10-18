#include "gnode.h"
#include "gedge.h"

GNode::~GNode() {
    for (GEdge * edge : m_Out)
        delete edge;
}
void GNode::add_out(const GNode * node, const char & label) {
    m_Out.push_back(new GEdge(node, label));
}
