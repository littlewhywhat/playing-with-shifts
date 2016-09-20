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
            return (a & m_Mask) == (b & m_Mask);
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
        wt.sort(s.bids());        
        //std::cout << wt << std::endl; 
        Cmp equal(s.bids());
        const std::vector<uint64_t> words = wt.words();          
        uint64_t max_comb_val = (uint64_t)1 << s.bids().size();
        uint64_t last_comb_val = max_comb_val - 1;
        auto word_it = words.begin();
        uint64_t word = *word_it;
        uint64_t comb_val = 0;
        uint64_t comb_val_p = create_comb(comb_val, s.bids());
        while ((word_it != words.end() && equal(word, comb_val_p)) && (comb_val < last_comb_val)) {
            word_it++;
            while ((word_it != words.end()) 
                    && equal(*word_it, word))
                word_it++;
            word = *word_it;
            comb_val_p = create_comb(++comb_val, s.bids());
        }
        return comb_val == last_comb_val && word_it != words.end() && equal(word, comb_val_p);

    }
};

#endif
