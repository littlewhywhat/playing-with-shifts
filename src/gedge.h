#ifndef GEDGE_H
#define GEDGE_H

class GNode;

class GEdge {
  public:
    GEdge(GNode * node, char label) : m_Label(label), m_Node(node) {}
    char m_Label;
    GNode * m_Node;
};

#endif