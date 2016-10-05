#ifndef MODE1_H
#define MODE1_H

#include <cstdint>
#include <vector>
#include <set>

#include "tablemode.h"

class Mode1 : public TableMode {
  private:
    class Less {
      private:
        uint64_t m_Mask;
      public:
        Less(const uint64_t & mask) : m_Mask(mask) {}
        bool operator() (const uint64_t & a, const uint64_t & b) const {
            return (a & m_Mask) < (b & m_Mask);
        }
    };
    bool good_strat_tm(const uint64_t & max_comb_val, const uint64_t & s_val) const override{
        Less less(s_val);
        std::set<uint64_t, Less> combset(less);
        for (auto word : get_wt().words()) 
            if (combset.find(word) == combset.end()) {
                combset.insert(word);
                if (combset.size() == max_comb_val)
                    return true;
            }
        return false;
    }
  public:
    Mode1(const uint32_t & wordlen) : TableMode(wordlen) {}
    ~Mode1() override {}  
    static Mode * create(const uint32_t & wordlen) {
        return new Mode1(wordlen);
    }
};

#endif
