#ifndef WORDTABLE_H
#define WORDTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cstdint>
#include <list>
#include <algorithm>

#include "comb.h"

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
    bool has(const Comb & comb) const {
        for (const std::string & word : m_Words) {
            uint32_t cnt_ltr_matches = 0;
            auto cvals = comb.vals();
            for (auto id_lttr : cvals) {
                uint32_t id = id_lttr.first;
                char letter = id_lttr.second;
                if (word.size() <= id || 
                        word.at(id) != letter)
                    break;
                cnt_ltr_matches++;
            }
            if (cnt_ltr_matches == cvals.size())
                return true;
        }
        return false;
    }
    std::list<std::string> findAll(const Comb & comb) const {
        std::list<std::string> s_words;
        for (const std::string & word : m_Words) {
            uint32_t cnt_ltr_matches = 0;
            auto cvals = comb.vals();
            for (auto id_lttr : cvals) {
                uint32_t id = id_lttr.first;
                char letter = id_lttr.second;
                if (word.size() <= id || 
                        word.at(id) != letter)
                    break;
                cnt_ltr_matches++;
            }
            if (cnt_ltr_matches == cvals.size())
                s_words.push_back(word);
        }
        return s_words;
    }
    friend std::ostream & operator << (std::ostream & out, const WordTable & src) {
        for (auto word : src.m_Words)
            out << word << std::endl;
        return out;
    }
};

#endif
