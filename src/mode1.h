#ifndef MODE1_H
#define MODE1_H

#include <cstdint>
#include <vector>
#include <set>

#include "mode.h"

class Mode1 : public Mode {
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
    bool gs_mode(const std::vector<uint64_t> & words, const uint64_t & max_comb_val, const uint64_t & s_val) const override{
        Less less(s_val);
        std::set<uint64_t, Less> combset(less);
        for (auto word : words) 
            if (combset.find(word) == combset.end()) {
                combset.insert(word);
                if (combset.size() == max_comb_val)
                    return true;
            }
        return false;
    }
  public:
    ~Mode1() override {}  
};

#endif
