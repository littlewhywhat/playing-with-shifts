#ifndef MODE1_H
#define MODE1_H

#include <cstdint>
#include <list>

#include "mode.h"

class Mode1 : public Mode {
  private: 
    class Equal {
      private:
        uint64_t m_Mask;
      public:
        Equal(const std::vector<uint32_t> & bids) : m_Mask(0) {
            for (uint32_t bid : bids)
                m_Mask += 1 << bid;
        }
        bool operator() (const uint64_t a, const uint64_t b) const {
            return (a & m_Mask) < (b & m_Mask);
        }
    };
  public:
    ~Mode1() override {}  
    bool good_strat(const Strategy & s, WordTable & wt) const override{
        if (s.bids().empty())
            return true;
        Equal equal(s.bids());
        std::set<uint64_t, Equal> combset(equal);
        uint64_t max_comb_val = (uint64_t)1 << s.bids().size();
        const std::vector<uint64_t> words = wt.words();          
        if (wt.words().size() < max_comb_val)
            return false;
        for (uint64_t word : words) 
            if (combset.find(word) == combset.end())
                combset.insert(word);
        return combset.size() == max_comb_val;
    }
};

#endif
