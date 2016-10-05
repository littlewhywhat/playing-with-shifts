#ifndef MODE_H
#define MODE_H

#include "strategy.h"

class WordData;
class WordTable;
class WordTree;

class Mode {
  private:
    const uint32_t & m_Wordlen;
  protected:
    virtual bool has_wd() const = 0;
    virtual bool good_strat_ch(const Strategy & s) const = 0;
  public:
    Mode(const uint32_t & wordlen) : m_Wordlen(wordlen) {}
    virtual ~Mode() {};
    virtual WordData & get_wd() const = 0;
    const uint32_t & get_wordlen() const {
        return m_Wordlen;
    }
    bool good_strat(const Strategy & s) const {
        if (!has_wd())
            throw "WordData wasn't set!";
        return good_strat_ch(s); 
    }
};

#endif
