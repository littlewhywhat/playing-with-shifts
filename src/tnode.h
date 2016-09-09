#ifndef TNODE_H
#define TNODE_H

#include <vector>
#include <iostream>

class TNode {
  private:
    char m_Lbl;
    std::vector<TNode *> m_Children;
    void swap(const TNode & src) {
        m_Lbl = src.m_Lbl;
        if (src.hasChildren()) {
            for (TNode * child : src.m_Children) {
                TNode * node = new TNode();
                *node = *child;
                m_Children.push_back(node);
            }
        }
    }
    void deleteChildren(TNode * node) {
        for (TNode * child : node -> getChildren()) {
            delete child;
        }
    }
  public:
    static const uint32_t MAX_CHILD = 2;
    TNode() : m_Lbl(0) {} 
    TNode(char lbl) : m_Lbl(lbl) {}
    TNode(const TNode & src) {
        swap(src);
    }
    const TNode & operator = (const TNode & src) {
        if (this == &src)
            return src;
        deleteChildren(this);
        swap(src);
        return *this;
    }
    ~TNode() {
        deleteChildren(this);
    }
    void addChild(char lbl) {
        m_Children.push_back(new TNode(lbl));
    }
    TNode * getChild(char lbl) const {
        for (TNode * node : m_Children)
            if (node -> m_Lbl == lbl)
                return node;
        return NULL;
    }
    bool hasChild(char lbl) const {
        for (TNode * node : m_Children)
            if (node -> m_Lbl == lbl)
                return true;
        return false;
    }
    const std::vector<TNode *> & getChildren() const {
        return m_Children;
    }
    bool hasChildren() const { 
        return !m_Children.empty();
    }
    char getLbl() const {
        return m_Lbl;
    }
};

#endif
