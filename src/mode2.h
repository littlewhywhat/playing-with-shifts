#ifndef MODE2_H
#define MODE2_H

#include <cstdint>
#include <map>
#include <utility>
#include <set>
#include <list>

#include "mode.h"
#include "comb.h"

class Mode2 : public Mode {
  private:
    class Less {
      private:
        uint64_t m_Mask;
      public:
        Less(const std::vector<uint32_t> & bids) : m_Mask(0) {
            for (auto bid : bids)
                m_Mask += 1 << bid;
            m_Mask = ~m_Mask;
        }
        bool operator() (const uint64_t & a, const uint64_t & b) const {
            return (a & m_Mask) < (b & m_Mask);
        }
    };
  public:
    ~Mode2() override {}
    bool good_strat(const Strategy & s, WordTable & wt) const override {
        uint64_t max_comb_val = (uint64_t)1 << s.bids().size(); 
        const std::vector<uint64_t> & words = wt.words();
        if (words.size() < max_comb_val)
            return false;
        Less c(s.bids());
        std::map<uint64_t, uint64_t, Less> g_words(c);
        for (uint64_t word : words) {
            auto search = g_words.find(word);
            uint64_t cnt;
            if (search == g_words.end()) {
                cnt = 1;
                g_words.insert(std::make_pair(word, cnt));
            }
            else {
                search -> second += 1;
                cnt = search -> second;
            }
            if (cnt == max_comb_val)
                return true;
        }
        return false;
    }
};

#endif
