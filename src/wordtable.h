#ifndef WORDTABLE_H
#define WORDTABLE_H

#include <ostream>
#include <string>
#include <vector>
#include <cstdint>

class WordTable {
  private:
    uint32_t m_WordLen;
    std::vector<uint64_t> m_Words;
    uint64_t s2i(const std::string & s) const {
        uint64_t i = 0;
        for (uint32_t pos = 0; pos < s.length(); pos++)
            if (s.at(pos) - '0')
                i += 1 << pos;
        return i;
    }
    std::string i2s(uint64_t word_val) const {
        std::string s;
        for (uint32_t i = 0; i < m_WordLen; i++) {
            if (word_val & 1)
                s.push_back('1');
            else
                s.push_back('0');
            word_val >>= 1;
        }

        return s;
    }
  public:
    WordTable(const uint32_t & wordlen) : m_WordLen(wordlen) {}
    void add(const std::string & word) {
        m_Words.push_back(s2i(word));
    }
    const std::vector<uint64_t> & words() const {
        return m_Words;
    }
    friend std::ostream & operator << (std::ostream & out, const WordTable & src) {
        for (auto word : src.m_Words)
            out << src.i2s(word) << std::endl;
        return out;
    }
};

#endif
