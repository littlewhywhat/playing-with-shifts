#ifndef MODE2_H
#define MODE2_H

#include <cstdint>
#include <map>
#include <utility>
#include <set>
#include <list>

#include "mode.h"

class Mode2 : public Mode {
  private:
    class InverseLess {
      private:
        uint64_t m_Mask;
      public:
        InverseLess(const uint64_t & mask) : m_Mask(~mask) {}
        bool operator() (const uint64_t & a, const uint64_t & b) const {
            return (a & m_Mask) < (b & m_Mask);
        }
    };

  public:
    ~Mode2() override {}
    bool good_strat(const Strategy & s, const WordTable & wt) const override {
        uint64_t max_comb_val = (uint64_t)1 << s.countB(); 
        const std::vector<uint64_t> & words = wt.words();
        if (words.size() < max_comb_val)
            return false;
        InverseLess c(s.val());
        std::map<uint64_t, uint64_t, InverseLess> g_words(c);
        for (auto word : words) {
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
