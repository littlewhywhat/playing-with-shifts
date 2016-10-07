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
    virtual std::ostream & print(std::ostream & out) const = 0;
    virtual const uint32_t & wordlen() const {
        return m_Wordlen;
    };
    friend std::ostream & operator << (std::ostream & out, const Language & src) {
        return src.print(out);
    }
};
#endif
