#ifndef MODE1_H
#define MODE1_H

#include <cstdint>
#include <list>

#include "mode.h"

class Mode1 : public Mode {
  private:
    
  public:
    ~Mode1() override {}  
    bool good_strat(const Strategy & s, const WordTable & wt) const override{
        if (!s.val())
            return true;
        Less less(s.val());
        std::set<uint64_t, Less> combset(less);
        uint64_t max_comb_val = (uint64_t)1 << s.countB();
        const std::vector<uint64_t> & words = wt.words();          
        if (wt.words().size() < max_comb_val)
            return false;
        for (auto word : words) 
            if (combset.find(word) == combset.end())
                combset.insert(word);
        return combset.size() == max_comb_val;
    }
};

#endif
