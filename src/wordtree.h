#ifndef WORDTREE_H
#define WORDTREE_H

#include <iostream>
#include <iomanip>
#include <iostream>

#include "tnode.h"

class WordTree {
  private:
    TNode * m_Root;
    void propagate(TNode * node, const std::string & word, uint32_t i) {
        if (i == word.length())
            return;
        if (!node -> hasChild(word.at(i)))
            node -> addChild(word.at(i));
        propagate(node -> getChild(word.at(i)), word, i + 1); 
    }
    void swap(const WordTree & src) {
        m_Root = new TNode();
        *m_Root = *src.m_Root;
    }
    static void postorder(std::ostream & out, const TNode * node, int indent) {
        if (node) {
            out << std::setw(indent);
            out << node -> getLbl() << std::endl;
            for (const TNode * child : node -> getChildren())
                postorder(out, child, indent + 4);
        }
    }

  public:
    WordTree() : m_Root(new TNode()) {}
    ~WordTree() {
        std::cout << "Destruct" << std::endl;
        delete m_Root;
    }
    WordTree(const WordTree & src) {
        std::cout << "Copy" << std::endl;
        swap(src);
    }
    const WordTree & operator = (const WordTree & src) {
        if (this == &src)
            return src;
        delete m_Root;
        swap(src);
        return *this;
   }
    void addWord(const std::string & word) {
        propagate(m_Root, word, 0);
    }
    
    friend std::ostream & operator << (std::ostream & out, const WordTree & tree) {
        postorder(out, tree.m_Root, 0);
        return out;
    }
};

#endif
