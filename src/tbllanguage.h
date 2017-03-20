#ifndef WORDTABLE_H
#define WORDTABLE_H

#include <ostream>
#include <vector>
#include <cstdint>

#include "language.h"

class TblLanguage : public Language {
  private:
    std::vector<uint64_t> m_Words;
  public:
    TblLanguage(const uint32_t & wordlen) : Language(wordlen) {}
    uint32_t size() const;
    void add(const std::string & word) override;
    friend std::vector<uint64_t>::const_iterator begin(const TblLanguage & src) {
        return src.m_Words.cbegin();
    }
    friend std::vector<uint64_t>::const_iterator end(const TblLanguage & src) {
        return src.m_Words.cend();
    }

    void clear() override;
};

#endif
