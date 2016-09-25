#ifndef MODE2_H
#define MODE2_H

#include <cstdint>
#include <vector>
#include <map>
#include <utility>

#include "tablemode.h"

class Mode2 : public TableMode {
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
    bool gs_mode(const std::vector<uint64_t> & words, const uint64_t & max_comb_val, const uint64_t & s_val) const override {
        InverseLess c(s_val);
        std::map<uint64_t, uint64_t, InverseLess> words_map(c);
        for (auto word : words) {
            auto search = words_map.find(word);
            if (search == words_map.end()) 
                words_map.insert(std::make_pair(word, 1)); 
            else {
                search -> second += 1;
                if (search -> second  == max_comb_val)
                    return true;
            }
        }
        return false;
    }
  public:
    ~Mode2() override {}
};

#endif
