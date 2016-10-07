#ifndef TRLANGUAGE_H
#define TRLANGUAGE_H

#include <string>
#include <ostream>

#include "tnode.h"

class TrLanguage : public Language {
  private:
    TNode m_Tree;
    void add_word(TNode & node, const std::string word, uint32_t pos) {
        if (pos == word.length())
            return;
        if (word.at(pos) == '0') {
            if (!node.has_zero())
                node.set_zero(new TNode());
            add_word(node.zero(), word, pos + 1);
        }
        if (word.at(pos) == '1') {
            if (!node.has_one())
                node.set_one(new TNode());
            add_word(node.one(), word, pos + 1);
        }
    }
  public:
    TrLanguage(const uint32_t & wordlen) : Language(wordlen) {}
    const TNode & root() const {
        return m_Tree;
    }
    void add(const std::string & word) override {
        add_word(m_Tree, word, 0);
    }
    std::ostream & print(std::ostream & out) const override {
        out << m_Tree;
        return out;
    }
};

#endif
