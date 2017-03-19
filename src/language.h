#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <string>

class Language {
  private:
    const uint32_t m_Wordlen;
  public:
    Language(const uint32_t & wordlen) : m_Wordlen(wordlen) {}
    virtual ~Language() {}
    virtual void add(const std::string & word) = 0;
    const uint32_t & wordlen() const { return m_Wordlen; };
};
#endif
