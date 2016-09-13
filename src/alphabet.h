#ifndef ALPHABET_H
#define ALPHABET_H

#include <vector> 

class Alphabet {
  private:
    std::vector<char> m_Letters;
  public:
    void add(char letter) {
        m_Letters.push_back(letter);
    }
    const std::vector<char> & letters() const {
        return m_Letters;
    }
};

#endif
