#ifndef GNODE_H
#define GNODE_H

#include <vector>

#include "gedge.h"

class GNode {
  private:
    const uint32_t m_Val;
    std::vector<GEdge*> m_Out;
  public:
    GNode(const uint32_t & val) : m_Val(val) {}
    ~GNode() {
        for (GEdge * edge : m_Out)
            delete edge;
    }
    const uint32_t & val() const {
        return m_Val;
    }
    void add_out(const GNode * node, const char & label) {
        m_Out.push_back(new GEdge(node, label));
    }
    const std::vector<GEdge*> & out() const {
        return m_Out;
    }
};

#endif
