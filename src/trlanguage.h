#ifndef TRLANGUAGE_H
#define TRLANGUAGE_H

#include <string>
#include <ostream>

#include "tnode.h"

class TrLanguage : public Language {
  private:
    TNode m_Tree;
    void add_word(TNode & node, const std::string word, uint32_t pos);
  public:
    TrLanguage(const uint32_t & wordlen) : Language(wordlen) {}
    const TNode & root() const { return m_Tree; }
    void add(const std::string & word) override;
    std::ostream & print(std::ostream & out) const override;
};

#endif
