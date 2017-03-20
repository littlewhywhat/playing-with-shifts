#include <string>
#include <ostream>

#include "tnode.h"

void TNode::delete_node(TNode * & node) {
   if (node != NULL) {
       delete node;
       node = NULL;
   }
}

void TNode::print(std::ostream & out) const {
    std::string s;
    print(out, s);
}

void TNode::print(std::ostream & out, std::string & buffer) const {
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

TNode::~TNode() {
   clear();
}

bool TNode::is_leaf() const {
    bool a = !m_Zero;
    bool b = !m_One;
    return a && b;
}

std::ostream & operator <<  (std::ostream & out, const TNode & src) {
    src.print(out);
    return out;
}

void TNode::clear() {
    delete_node(m_Zero);
    delete_node(m_One);
}
