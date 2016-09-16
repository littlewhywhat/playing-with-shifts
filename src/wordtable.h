#ifndef WORDTABLE_H
#define WORDTABLE_H

#include <string>
#include <vector>
#include <utility>
#include <cstdint>

class WordTable {
  private:
      std::vector<std::string> m_Words;
      uint32_t m_Wordlen;
  public:
    WordTable(uint32_t wordlen) : m_Wordlen(wordlen) {}
    void add(const std::string & word) {
        if (word.size() != m_Wordlen)
            throw "Not right length of the word to add";
        m_Words.push_back(word);
    }
    bool has(const std::vector<std::pair<uint32_t, char>> & id_letters) const {
        for (const std::string & word : m_Words) {
            uint32_t cnt_matches = 0;
            for (auto id_lttr : id_letters) {
                uint32_t id = id_lttr.first;
                uint32_t letter = id_lttr.second;
                if (word.at(id) != letter)
                    break;
                cnt_matches++;
            }
            if (cnt_matches == id_letters.size())
                return true;
        }
        return false;
    }
};

#endif
