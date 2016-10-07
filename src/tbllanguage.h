#ifndef WORDTABLE_H
#define WORDTABLE_H

#include <ostream>
#include <string>
#include <vector>
#include <cstdint>

#include "utils.h"
#include "language.h"

class TblLanguage : public Language {
  private:
    std::vector<uint64_t> m_Words;
  public:
    TblLanguage(const uint32_t & wordlen) : Language(wordlen) {}
    uint32_t size() const {
        return m_Words.size();
    }
    void add(const std::string & word) override {
        m_Words.push_back(s2i(word));
    }
    friend std::vector<uint64_t>::const_iterator begin(const TblLanguage & src) {
        return src.m_Words.cbegin();
    }
    friend std::vector<uint64_t>::const_iterator end(const TblLanguage & src) {
        return src.m_Words.cend();
    }
    std::ostream & print(std::ostream & out) const override {
        for (auto word : m_Words)
            out << i2s(word, wordlen()) << std::endl;
        return out;
    }
};

#endif
