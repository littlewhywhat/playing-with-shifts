#ifndef MAXBCNT_H
#define MAXBCNT_H

#include <cstdint>
#include <ostream>

#include "mode.h"
#include "strategy.h"

class MaxBCnt {
  private:
    const Mode & m_Mode;
  public:
    MaxBCnt(const Mode & mode) : m_Mode(mode) {} 
    uint32_t compute(std::ostream * out) const {
        uint32_t maxBcnt = 0;   
        if (out)
            *out << "good strategies are: " << std::endl;
        uint64_t strat_bound = (uint64_t)1 << m_Mode.get_wordlen();
        for (uint64_t strat_val = 1; strat_val < strat_bound; strat_val++) {
            Strategy strat(strat_val, m_Mode.get_wordlen());
            uint32_t bcnt = strat.Bcnt();
            if (bcnt > maxBcnt && m_Mode.good_strat(strat)) {
                if (out)
                    *out << strat << std::endl;
                maxBcnt = bcnt;
            }
        }
        return maxBcnt;
    }
};

#endif
