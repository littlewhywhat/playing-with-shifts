#ifndef TRLANGUAGE_H
#define TRLANGUAGE_H

#include <string>
#include <ostream>

#include "tnode.h"
#include "wordstructure.h"

class WordTree : public WordStructure {
  private:
    TNode m_Tree;
    void add_word(TNode & node, const std::string & word, uint32_t pos);
  public:
    WordTree() : WordStructure() {}
    TNode & root() { return m_Tree; }
    const TNode & root() const { return m_Tree; }
    void add(const std::string & word) override;
    void clear() override;
};

#endif
