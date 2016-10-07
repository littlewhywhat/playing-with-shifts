#ifndef WORDDATA_H
#define WORDDATA_H

#include <string>

class WordData {
  private:
    const uint32_t m_Wordlen;
  public:
    WordData(const uint32_t & wordlen) : m_Wordlen(wordlen) {}
    virtual ~WordData() {}
    virtual void add(const std::string & word) = 0;
    virtual std::ostream & print(std::ostream & out) const = 0;
    virtual const uint32_t & wordlen() const {
        return m_Wordlen;
    };
    friend std::ostream & operator << (std::ostream & out, const WordData & src) {
        return src.print(out);
    }
};
#endif
