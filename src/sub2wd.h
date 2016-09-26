#ifndef SUB2WD_H
#define SUB2WD_H

#include <cstdint>
#include <string>

#include "worddata.h"
#include "subshift.h"

class Sub2Wd {
  private:
    std::string i2s(uint64_t val, uint32_t wordlen) const {
        std::string s;
        for (uint32_t i = 0; i < wordlen; i++) {
            s.push_back((val & 1) + '0');
            val >>= 1;
        }
        return s;
    }
  public:
    void translate(WordData & wd, const uint32_t & wordlen, const Subshift & subsh) const {
        uint64_t max_comb = 1 << ((uint64_t) wordlen);
        for (uint64_t comb = 0; comb < max_comb; comb++) 
            if (subsh.in(comb, wordlen))
                wd.add(i2s(comb, wordlen));
    }
};

#endif
