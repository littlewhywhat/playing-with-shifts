#ifndef TNODE_H
#define TNODE_H

#include <string>
#include <ostream>

class TNode {
  private:
    const char ZERO = '0';
    const char ONE = '1';
    TNode * m_Zero;
    TNode * m_One;
    void delete_node(TNode * node);
    void print(std::ostream & out, std::string & buffer) const;
  public:
    void print(std::ostream & out) const;
    TNode(TNode * zero, TNode * one) : m_Zero(zero), m_One(one) {}
    TNode(TNode * zero) : TNode(zero, NULL) {}
    TNode() : TNode(NULL, NULL) {}
    ~TNode();
    void set_one(TNode * one) { m_One = one; }
    void set_zero(TNode * zero) { m_Zero = zero; }
    bool has_one() const { return m_One; }
    bool has_zero() const { return m_Zero; }
    bool is_leaf() const;
    TNode & one() const { return *m_One; }
    TNode & zero() const { return *m_Zero; }
    friend std::ostream & operator <<  (std::ostream & out, const TNode & src);
    
};

#endif
