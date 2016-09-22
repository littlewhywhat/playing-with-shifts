#ifndef WORDTABLE_H
#define WORDTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cstdint>
#include <list>
#include <algorithm>

class WordTable {
  private:
    std::vector<std::string> m_Words;
    std::vector<uint64_t> m_WordsI;
    uint64_t s2i(const std::string & s) const {
        uint64_t i = 0;
        for (uint32_t pos = 0; pos < s.length(); pos++)
            if (s.at(pos) - '0')
                i += 1 << pos;
        return i;
    }
  public:
    void add(const std::string & word) {
        m_Words.push_back(word);
        m_WordsI.push_back(s2i(word));
    }
    const std::vector<uint64_t> & words() const {
        return m_WordsI;
    }
    friend std::ostream & operator << (std::ostream & out, const WordTable & src) {
        for (auto word : src.m_Words)
            out << word << std::endl;
        return out;
    }
};

#endif
