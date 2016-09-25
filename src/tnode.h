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
    void delete_node(TNode * node) {
       if (node != NULL) 
           delete node;
    }
    void print(std::ostream & out, std::string & buffer) const {
        if (is_leaf()) {
            out << buffer << std::endl;
            return;
        }
        if (m_Zero) {
            buffer.push_back(ZERO);
            m_Zero -> print(out, buffer);
            buffer.pop_back();
        }
        if (m_One) {
            buffer.push_back(ONE);
            m_One -> print(out, buffer);
            buffer.pop_back();
        }
    }
  public:
    TNode(TNode * zero, TNode * one) : m_Zero(zero), m_One(one) {}
    TNode(TNode * zero) : TNode(zero, NULL) {}
    TNode() : TNode(NULL, NULL) {}
    ~TNode() {
        delete_node(m_Zero);
        delete_node(m_One);
     }
    void set_one(TNode * one) {
        m_One = one;
    }   
    void set_zero(TNode * zero) {
        m_Zero = zero;
    } 
    bool has_one() const {
        return m_One;
    }
    bool has_zero() const {
        return m_Zero;
    }
    bool is_leaf() const {
        bool a = !m_Zero;
        bool b = !m_One;
        return a && b;
    }
    TNode & one() const {
        return *m_One;
    }
    const TNode & zero() const {
        return *m_Zero;
    }
    TNode & one() {
        return *m_One;
    }
    TNode & zero() {
        return *m_Zero;
    }
    friend std::ostream & operator <<  (std::ostream & out, const TNode & src) {
        std::string s;
        src.print(out, s);
        return out; 
    }
};

#endif