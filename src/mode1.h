#ifndef MODE1_H
#define MODE1_H

#include <cstdint>
#include <list>

#include "mode.h"

class Mode1 : public Mode {
  private: 
    class Cmp {
      private:
        uint64_t m_Mask;
      public:
        Cmp(const std::vector<uint32_t> & bids) : m_Mask(0) {
            for (uint32_t bid : bids)
                m_Mask += 1 << bid;
        }
        bool operator() (const uint64_t a, const uint64_t b) const {
            return (a & m_Mask) < (b & m_Mask);
        }
    };
    uint64_t create_comb(uint64_t val, const std::vector<uint32_t> & bids) const {
        uint64_t comb = 0;
        for (auto bid : bids) {
            comb += ( val & 1 ) << bid;
            val >>= 1;
        }
        //std::cout << comb << std::endl;
        return comb;

    } 
  public:
    ~Mode1() override {}  
    bool good_strat(const Strategy & s, WordTable & wt) const override{
        if (s.bids().empty())
            return true;
        Cmp equal(s.bids());
        std::set<uint64_t, Cmp> combset(equal);
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
