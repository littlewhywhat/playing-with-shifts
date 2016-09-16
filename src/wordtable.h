#ifndef WORDTABLE_H
#define WORDTABLE_H

#include <string>
#include <vector>
#include <utility>
#include <cstdint>

class WordTable {
  private:
      std::vector<std::string> m_Words;
  public:
    void add(const std::string & word) {
        m_Words.push_back(word);
    }
    bool has(const std::vector<std::pair<uint32_t, char>> & id_letters) const {
        for (const std::string & word : m_Words) {
            uint32_t cnt_ltr_matches = 0;
            for (auto id_lttr : id_letters) {
                uint32_t id = id_lttr.first;
                char letter = id_lttr.second;
                if (word.size() <= id || 
                        word.at(id) != letter)
                    break;
                cnt_ltr_matches++;
            }
            if (cnt_ltr_matches == id_letters.size())
                return true;
        }
        return false;
    }
    std::list<std::string> findAll(const std::vector<std::pair<uint32_t, char>> & id_letters) const {
        std::list<std::string> s_words;
        for (const std::string & word : m_Words) {
            uint32_t cnt_ltr_matches = 0;
            for (auto id_lttr : id_letters) {
                uint32_t id = id_lttr.first;
                char letter = id_lttr.second;
                if (word.size() <= id || 
                        word.at(id) != letter)
                    break;
                cnt_ltr_matches++;
            }
            if (cnt_ltr_matches == id_letters.size())
                s_words.push_back(word);
        }
        return s_words;
    }
};

#endif
