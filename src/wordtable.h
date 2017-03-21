#ifndef WORDTABLE_H
#define WORDTABLE_H

#include <ostream>
#include <vector>
#include <cstdint>

#include "wordstructure.h"

class WordTable : public WordStructure {
  private:
    std::vector<uint64_t> m_Words;
  public:
    WordTable() : WordStructure() {}
    uint32_t size() const;
    void add(const std::string & word) override;
    friend std::vector<uint64_t>::const_iterator begin(const WordTable & src) {
        return src.m_Words.cbegin();
    }
    friend std::vector<uint64_t>::const_iterator end(const WordTable & src) {
        return src.m_Words.cend();
    }

    void clear() override;
};

#endif
