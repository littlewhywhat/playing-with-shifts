#ifndef GEDGE_H
#define GEDGE_H

class GNode;

class GEdge {
  public:
    GEdge(const GNode * node, const char & label) : m_Label(label), m_Node(node) {}
    const char m_Label;
    const GNode * m_Node;
};

#endif
