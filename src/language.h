//
// Created by vaivorom on 3/21/17.
//

#ifndef PLAYING_WITH_SHIFTS_LANGUAGE_H
#define PLAYING_WITH_SHIFTS_LANGUAGE_H


#include <string>
#include <set>

class Language {
  private:
    std::set<std::string> m_Words;
  public:
    Language() {}
    void insert(const std::string & word) {
        if (m_Words.find(word) == m_Words.end())
            m_Words.insert(word);
    }
    bool has(const std::string & word) { return m_Words.find(word) != m_Words.end(); }
    friend std::set<std::string>::const_iterator begin(const Language & src) {
        return src.m_Words.cbegin();
    }
    friend std::set<std::string>::const_iterator end(const Language & src) {
        return src.m_Words.cend();
    }
};


#endif //PLAYING_WITH_SHIFTS_LANGUAGE_H
